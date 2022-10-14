import angr

proj = angr.Project('keygenme')
simgr = proj.factory.simgr()
simgr.explore(find=lambda s: b" valid" in s.posix.dumps(1))
s = simgr.found[0]
print(s.posix.dumps(0).decode())