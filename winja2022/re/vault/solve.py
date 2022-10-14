import angr
import claripy
import sys

def main():
    #flag    = claripy.BVS('flag', 20*8, explicit_name=True)# symbolized flag, we know the length by looking at the assembly code
    base_addr = 0x100000
    input_len = 49

    p = angr.Project('./vault', main_opts={'base_addr': base_addr}, auto_load_libs=False)
    flag_chars = [claripy.BVS('flag_%d' % i, 8) for i in range(input_len)]

    flag = claripy.Concat( *flag_chars + [claripy.BVV(b'\x00')])

    st = p.factory.entry_state(args=['./engine',flag])

    for k in flag_chars:
        st.solver.add(k < 0x7f)
        st.solver.add(k > 0x20)

    sm = p.factory.simulation_manager(st)
    sm.explore(find=0x00101462)

    if (len(sm.found) > 0):
        s = sm.found[0]
        print(s)
        return s.posix.dumps(0)
    else:
        return b"no flag"


    #y = []
    #for x in sm.deadended:
    #    dump = x.posix.dumps(1)
    #    print(dump)
    #    if b"flag" in dump:
    #        return next(filter(lambda s: b'flag{' in s, out.split()))

if __name__ in '__main__':
    print(main())