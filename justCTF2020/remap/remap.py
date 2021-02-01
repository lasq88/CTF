import types, marshal,sys

replacement_matrix = {9:2,17:16,52:9,54:5,56:6,60:4,64:1,71:3,97:100,103:111,125:90,157:112,162:89}
f = open('backup_decryptor.pyc', 'rb')
bytes = f.read()
f.close()
code_bytes = bytes[16:]
code_object = marshal.loads(code_bytes)
new_code_obj = recurse_convert_code_objects(code_object)
#bytecode = code_object.co_code
#opcodes = set()
def convert_opcodes(code_obj_in):
    new_co_code = b''
    switch = True
    for byte in code_obj_in:
        if (switch):
            new_co_code += opcode_replace(byte).to_bytes(1, 'big')
        else:
            new_co_code += byte.to_bytes(1, 'big')
        switch = not switch
    return new_co_code
 
def opcode_replace(byte):
    if byte in replacement_matrix:
        return replacement_matrix[byte]
    else:
       return byte

def recurse_convert_code_objects(code_obj_in):
    new_co_code = convert_opcodes(code_obj_in.co_code)
    new_co_const = []
    for const in code_obj_in.co_consts:
        if type(const) == types.CodeType:
            new_const = recurse_convert_code_objects(const)
            new_co_const.append(new_const)
        else:
            new_co_const.append(const)
    new_code_obj_out = types.CodeType(
        code_obj_in.co_argcount,
        code_object.co_posonlyargcount,
        code_object.co_kwonlyargcount,
        code_obj_in.co_nlocals,
        code_obj_in.co_stacksize,
        code_obj_in.co_flags,
        new_co_code,
        tuple(new_co_const),
        code_obj_in.co_names,
        code_obj_in.co_varnames,
        code_obj_in.co_filename,
        code_obj_in.co_name,
        code_obj_in.co_firstlineno,
        code_obj_in.co_lnotab,
        code_obj_in.co_freevars,
        code_obj_in.co_cellvars
    )
    return new_code_obj_out
    
