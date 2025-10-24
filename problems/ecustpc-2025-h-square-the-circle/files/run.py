
# 保存为 run_local.py
import subprocess, threading, sys

INTERACTOR = "Square_The_Circle_Interactor.exe"   # 或 "./interactor"
SOLUTION   = "Square_The_Circle_MainCorrect.exe"     # 或 "./solution"
INPUT_FILE = "input1.in"
TOUT_FILE  = "tout.txt"

interactor = subprocess.Popen(
    [INTERACTOR, INPUT_FILE, TOUT_FILE],   # 注意：没给 Answer_File
    stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    bufsize=1, text=True
)
solution = subprocess.Popen(
    [SOLUTION],
    stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    bufsize=1, text=True
)

def pump(src, dst, tag):
    for line in src:
        sys.stdout.write(f"[{tag}] {line}")
        sys.stdout.flush()
        try:
            dst.write(line); dst.flush()
        except BrokenPipeError:
            break

t1 = threading.Thread(target=pump, args=(interactor.stdout, solution.stdin, "interactor→sol"))
t2 = threading.Thread(target=pump, args=(solution.stdout, interactor.stdin, "sol→interactor"))
t1.start(); t2.start()

def pump_err(p, name):
    for line in p.stderr:
        sys.stderr.write(f"[{name} err] {line}")
        sys.stderr.flush()

te1 = threading.Thread(target=pump_err, args=(interactor, "interactor"))
te2 = threading.Thread(target=pump_err, args=(solution, "solution"))
te1.start(); te2.start()

t1.join(); t2.join()
try:
    interactor.stdin.close()
    solution.stdin.close()
except Exception:
    pass
ret_i = interactor.wait(); ret_s = solution.wait()
print(f"\nExit codes: interactor={ret_i}, solution={ret_s}")