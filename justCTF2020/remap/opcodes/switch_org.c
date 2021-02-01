        switch(opcode) {
        case (int **)0x1:
          goto opcode_switch_caseD_1;
        case (int **)0x2:
          piVar7 = ppiVar16[-1];
          ppiVar16[-1] = ppiVar16[-2];
          ppiVar16[-2] = piVar7;
          goto LAB_101b8a90;
        case (int **)0x3:
          piVar7 = ppiVar16[-1];
          ppiVar16[-1] = ppiVar16[-2];
          ppiVar16[-2] = ppiVar16[-3];
          ppiVar16[-3] = piVar7;
          goto LAB_101b8a90;
        case (int **)0x4:
          piVar7 = ppiVar16[-1];
          *piVar7 = *piVar7 + 1;
          *ppiVar16 = piVar7;
          local_8c = ppiVar16 + 1;
          ppiVar13 = local_8c;
          goto LAB_101b8a90;
        case (int **)0x5:
          piVar7 = ppiVar16[-1];
          piVar15 = ppiVar16[-2];
          *piVar7 = *piVar7 + 1;
          *piVar15 = *piVar15 + 1;
          local_8c = ppiVar16 + 2;
          ppiVar16[1] = piVar7;
          *ppiVar16 = piVar15;
          ppiVar13 = local_8c;
          goto LAB_101b8a90;
        case (int **)0x6:
          piVar7 = ppiVar16[-1];
          ppiVar16[-1] = ppiVar16[-2];
          ppiVar16[-2] = ppiVar16[-3];
          ppiVar16[-3] = ppiVar16[-4];
          ppiVar16[-4] = piVar7;
          goto LAB_101b8a90;
        default:
          if (local_a0[10] == 0) {
            iVar6 = PyCode_Addr2Line(local_a0[4],local_a0[0xd]);
          }
          else {
            iVar6 = local_a0[0xe];
          }
          uVar10 = (*local_38)(2,"XXX lineno: %d, opcode: %d\n",iVar6,opcode);
          FUN_1007dc80(uVar10);
          _PyErr_SetString(local_9c,PyExc_SystemError,"unknown opcode");
          param_1 = local_a0;
          goto LAB_101b869b;
        case (int **)0x9:
          goto LAB_101b8a90;
        case (int **)0xa:
          goto opcode_switch_caseD_a;
        case (int **)0xb:
          piVar7 = ppiVar16[-1];
          ppiStack128 = (int **)piVar7;
          if (piVar7 == (int *)0x0) {
            if ((DAT_103b673c == (int **)0x0) || (DAT_103b673c[0xd] == (int *)0x0)) {
              ppiStack152 = DAT_103b673c;
              ppiStack144 = (int **)FUN_10175160(puVar12,0,0);
              _PyErr_SetObject(ppiStack152,puVar20,ppiStack144);
              piVar7 = (int *)ppiStack128;
              if ((ppiStack144 != (int **)0x0) &&
                 (*ppiStack144 = (int *)((int)*ppiStack144 + -1), *ppiStack144 == (int *)0x0)) {
                (*(code *)ppiStack144[1][6])(ppiStack144);
                piVar7 = (int *)ppiStack128;
              }
            }
LAB_101b9c4d:
            ppiStack128 = (int **)0x0;
          }
          else {
            iVar6 = *(int *)(piVar7[1] + 0x30);
            if ((iVar6 == 0) || (pcVar9 = *(code **)(iVar6 + 0x18), pcVar9 == (code *)0x0)) {
              PyErr_Format(PyExc_TypeError,"bad operand type for unary -: \'%.200s\'",
                           *(undefined4 *)(piVar7[1] + 0xc));
              goto LAB_101b9c4d;
            }
            ppiStack128 = (int **)(*pcVar9)(piVar7);
          }
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          *(int ***)(ppiVar16 + -1) = ppiStack128;
          opcode = ppiStack128;
          goto joined_r0x101b9c73;
        case (int **)0xc:
          piVar7 = ppiVar16[-1];
          ppiStack136 = ppiVar16 + -1;
          ppiStack152 = (int **)PyObject_IsTrue(piVar7);
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          piVar7 = local_a0;
          if (ppiStack152 == (int **)0x0) {
            _Py_TrueStruct = _Py_TrueStruct + 1;
            *ppiStack136 = &_Py_TrueStruct;
          }
          else {
            ppiVar13 = ppiStack136;
            param_1 = local_a0;
            if ((int)ppiStack152 < 1) goto LAB_101b869b;
            _Py_FalseStruct = _Py_FalseStruct + 1;
            *ppiStack136 = &_Py_FalseStruct;
            ppiVar13 = ppiVar16;
          }
          goto LAB_101b8915;
        case (int **)0xf:
          piVar7 = ppiVar16[-1];
          ppiStack128 = (int **)piVar7;
          if (piVar7 == (int *)0x0) {
            if ((DAT_103b673c == (int **)0x0) || (DAT_103b673c[0xd] == (int *)0x0)) {
              ppiStack152 = DAT_103b673c;
              ppiStack144 = (int **)FUN_10175160(puVar12,0,0);
              _PyErr_SetObject(ppiStack152,puVar20,ppiStack144);
              piVar7 = (int *)ppiStack128;
              if ((ppiStack144 != (int **)0x0) &&
                 (*ppiStack144 = (int *)((int)*ppiStack144 + -1), *ppiStack144 == (int *)0x0)) {
                (*(code *)ppiStack144[1][6])(ppiStack144);
                piVar7 = (int *)ppiStack128;
              }
            }
LAB_101b9d91:
            ppiStack128 = (int **)0x0;
          }
          else {
            iVar6 = *(int *)(piVar7[1] + 0x30);
            if ((iVar6 == 0) || (pcVar9 = *(code **)(iVar6 + 0x28), pcVar9 == (code *)0x0)) {
              PyErr_Format(PyExc_TypeError,"bad operand type for unary ~: \'%.200s\'",
                           *(undefined4 *)(piVar7[1] + 0xc));
              goto LAB_101b9d91;
            }
            ppiStack128 = (int **)(*pcVar9)(piVar7);
          }
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          *(int ***)(ppiVar16 + -1) = ppiStack128;
          opcode = ppiStack128;
          goto joined_r0x101baa38;
        case (int **)0x10:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_MatrixMultiply(ppiStack152,oparg_var14);
          break;
        case (int **)0x11:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x8c,0x88,&DAT_10364f60);
          break;
        case (int **)0x13:
          ppiStack152 = (int **)ppiVar16[-2];
          local_8c = ppiVar16 + -1;
          oparg_var14 = (int **)*local_8c;
          ppiStack144 = (int **)FUN_100e6ff0(&_Py_NoneStruct,0x14,ppiStack152);
          break;
        case (int **)0x14:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_Multiply(ppiStack152,oparg_var14);
          break;
        case (int **)0x16:
          ppiStack152 = (int **)ppiVar16[-2];
          local_8c = ppiVar16 + -1;
          piVar7 = *local_8c;
          if ((ppiStack152[1] == (int *)&PyUnicode_Type) &&
             (((*(uint *)((undefined *)piVar7[1] + 0x54) & 0x10000000) == 0 ||
              ((undefined *)piVar7[1] == &PyUnicode_Type)))) {
            ppiStack136 = (int **)PyUnicode_Format(ppiStack152,piVar7);
          }
          else {
            ppiStack136 = (int **)PyNumber_Remainder(ppiStack152,piVar7);
          }
          goto LAB_101b9ed5;
        case (int **)0x17:
          ppiStack152 = (int **)ppiVar16[-2];
          ppiVar16 = ppiVar16 + -1;
          piVar7 = *ppiVar16;
          local_8c = ppiVar16;
          if ((ppiStack152[1] == (int *)&PyUnicode_Type) &&
             ((undefined *)piVar7[1] == &PyUnicode_Type)) {
            ppiStack136 = (int **)FUN_101bfcb0(piVar7,local_a0,puVar12);
          }
          else {
            ppiStack136 = (int **)PyNumber_Add(ppiStack152,piVar7);
            *ppiStack152 = (int *)((int)*ppiStack152 + -1);
            if (*ppiStack152 == (int *)0x0) {
              (*(code *)ppiStack152[1][6])(ppiStack152);
            }
          }
          *piVar7 = *piVar7 + -1;
          opcode = ppiStack136;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
            opcode = ppiStack136;
          }
          goto LAB_101b9b8e;
        case (int **)0x18:
          ppiStack152 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          oparg_var14 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_Subtract(oparg_var14,ppiStack152);
          break;
        case (int **)0x19:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyObject_GetItem(ppiStack152,oparg_var14);
          break;
        case (int **)0x1a:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_FloorDivide(ppiStack152,oparg_var14);
          break;
        case (int **)0x1b:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_TrueDivide(ppiStack152,oparg_var14);
          break;
        case (int **)0x1c:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x7c,0x74,&DAT_10364f64);
          break;
        case (int **)0x1d:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x80,0x78,&DAT_10364f68);
          break;
        case (int **)0x32:
          opcode = (int **)ppiVar16[-1];
          piVar7 = opcode[1];
          iVar6 = piVar7[10];
          if ((iVar6 == 0) || (pcVar9 = *(code **)(iVar6 + 4), pcVar9 == (code *)0x0)) {
            ppiVar16[-1] = (int *)0x0;
            _PyErr_Format(local_9c,PyExc_TypeError,
                          "\'async for\' requires an object with __aiter__ method, got %.100s",
                          piVar7[3]);
            goto LAB_101b8a45;
          }
          ppiStack152 = (int **)(*pcVar9)(opcode);
          *opcode = (int *)((int)*opcode + -1);
          if (*opcode == (int *)0x0) {
            (*(code *)opcode[1][6])(opcode);
          }
          if (ppiStack152 == (int **)0x0) goto LAB_101bc146;
          if ((ppiStack152[1][10] == 0) || (*(int *)(ppiStack152[1][10] + 8) == 0)) {
            ppiVar16[-1] = (int *)0x0;
            _PyErr_Format(local_9c,PyExc_TypeError,
                                                    
                          "\'async for\' received an object from __aiter__ that does not implement__anext__: %.100s"
                          ,ppiStack152[1][3]);
            opcode = ppiStack152;
            param_1 = local_a0;
            goto LAB_101bc1a8;
          }
          *(int ***)(ppiVar16 + -1) = ppiStack152;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x33:
          piVar7 = ppiVar16[-1];
          puVar20 = (undefined *)piVar7[1];
          if (puVar20 != &PyAsyncGen_Type) {
            if ((*(int *)(puVar20 + 0x28) == 0) ||
               (pcVar9 = *(code **)(*(int *)(puVar20 + 0x28) + 8), pcVar9 == (code *)0x0)) {
              _PyErr_Format(local_9c,PyExc_TypeError,
                            "\'async for\' requires an iterator with __anext__ method, got %.100s",
                            *(undefined4 *)(puVar20 + 0xc));
              param_1 = local_a0;
              goto LAB_101b869b;
            }
            opcode = (int **)(*pcVar9)(piVar7);
            param_1 = local_a0;
            if (opcode == (int **)0x0) goto LAB_101b869b;
            ppiStack152 = (int **)FUN_10123660();
            if (ppiStack152 != (int **)0x0) {
              *opcode = (int *)((int)*opcode + -1);
              if (*opcode == (int *)0x0) {
                (*(code *)opcode[1][6])(opcode);
              }
              *(int ***)ppiVar16 = ppiStack152;
              ppiVar16 = ppiVar16 + 1;
              local_8c = ppiVar16;
              goto LAB_101b9610;
            }
            _PyErr_FormatFromCause
                      (PyExc_TypeError,
                       "\'async for\' received an invalid object from __anext__: %.100s",
                       opcode[1][3]);
            goto LAB_101b8a45;
          }
          piVar7 = (int *)(**(code **)(iRam103a3088 + 8))(piVar7);
          param_1 = local_a0;
          if (piVar7 == (int *)0x0) goto LAB_101b869b;
          *ppiVar16 = piVar7;
          ppiVar16 = ppiVar16 + 1;
          local_8c = ppiVar16;
          goto LAB_101b9610;
        case (int **)0x34:
          opcode = (int **)ppiVar16[-1];
          ppiStack136 = opcode;
          piVar7 = (int *)_PyType_LookupId(opcode[1],&DAT_103b4e98);
          if (piVar7 == (int *)0x0) {
LAB_101bc0e6:
            param_1 = local_a0;
            if (local_9c[0xd] == (int *)0x0) {
              _PyErr_SetObject(local_9c,PyExc_AttributeError,DAT_103b4ea0);
            }
            goto LAB_101b869b;
          }
          if (*(code **)(piVar7[1] + 0x88) == (code *)0x0) {
            *piVar7 = *piVar7 + 1;
          }
          else {
            piVar7 = (int *)(**(code **)(piVar7[1] + 0x88))(piVar7,opcode,opcode[1]);
            if (piVar7 == (int *)0x0) goto LAB_101bc0e6;
          }
          ppiVar16[-1] = piVar7;
          piVar7 = (int *)_PyType_LookupId(opcode[1],&DAT_103b4ee0);
          if (piVar7 == (int *)0x0) {
LAB_101b94bc:
            if (local_9c[0xd] == (int *)0x0) {
              _PyErr_SetObject(local_9c,PyExc_AttributeError,DAT_103b4ee8);
              piVar7 = (int *)0x0;
            }
          }
          else {
            if (*(code **)(piVar7[1] + 0x88) == (code *)0x0) {
              *piVar7 = *piVar7 + 1;
            }
            else {
              piVar7 = (int *)(**(code **)(piVar7[1] + 0x88))(piVar7,ppiStack136,ppiStack136[1]);
              if (piVar7 == (int *)0x0) goto LAB_101b94bc;
            }
          }
          *ppiStack136 = (int *)((int)*ppiStack136 + -1);
          if (*ppiStack136 == (int *)0x0) {
            (*(code *)ppiStack136[1][6])(ppiStack136);
          }
          param_1 = local_a0;
          if (piVar7 == (int *)0x0) goto LAB_101b869b;
          ppiStack152 = (int **)FUN_101b70d0(0,0);
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          param_1 = local_a0;
          if (ppiStack152 == (int **)0x0) goto LAB_101b869b;
          *(int ***)ppiVar16 = ppiStack152;
          ppiVar16 = ppiVar16 + 1;
          ppiVar13 = ppiVar16;
          piVar7 = local_a0;
          local_8c = ppiVar16;
          if (*(char *)local_94 == 'I') {
            local_94 = (int *)((ushort *)local_94 + 1);
            goto opcode_switch_caseD_49;
          }
          goto LAB_101b8915;
        case (int **)0x35:
          *ppiVar16 = (int *)0x0;
          local_8c = ppiVar16 + 1;
          ppiVar13 = local_8c;
          goto LAB_101b8a90;
        case (int **)0x36:
          opcode = (int **)ppiVar16[-1];
          ppiVar16 = ppiVar16 + -1;
          ppiStack152 = (int **)PyExc_StopAsyncIteration;
          ppiStack136 = opcode;
          if ((opcode == (int **)0x0) || (PyExc_StopAsyncIteration == (undefined *)0x0))
          goto LAB_101b8e7b;
          ppiStack144 = *(int ***)(*(int *)(PyExc_StopAsyncIteration + 4) + 0x54);
          if (((uint)ppiStack144 & 0x4000000) != 0) {
            ppiStack144 = (int **)PyTuple_Size(PyExc_StopAsyncIteration);
            ppiStack120 = (int **)0x0;
            if ((int)ppiStack144 < 1) goto LAB_101b8e7b;
            ppiVar13 = ppiStack152 + 3;
            goto LAB_101b8e53;
          }
          ppiVar13 = opcode;
          if (((uint)opcode[1][0x15] & 0x40000000) != 0) {
            ppiVar13 = (int **)opcode[1];
          }
          if ((((ppiVar13[1][0x15] < 0) && (((uint)ppiVar13[0x15] & 0x40000000) != 0)) &&
              ((int)ppiStack144 < 0)) &&
             ((*(uint *)(PyExc_StopAsyncIteration + 0x54) & 0x40000000) != 0)) {
            uVar17 = PyType_IsSubtype(ppiVar13,PyExc_StopAsyncIteration);
          }
          else {
            uVar17 = (uint)(ppiVar13 == (int **)PyExc_StopAsyncIteration);
          }
          if (uVar17 == 0) goto LAB_101b8e7b;
          goto LAB_101b8ee3;
        case (int **)0x37:
          ppiStack152 = (int **)ppiVar16[-2];
          ppiVar16 = ppiVar16 + -1;
          piVar7 = *ppiVar16;
          local_8c = ppiVar16;
          if ((ppiStack152[1] == (int *)&PyUnicode_Type) &&
             ((undefined *)piVar7[1] == &PyUnicode_Type)) {
            ppiStack136 = (int **)FUN_101bfcb0(piVar7,local_a0,puVar12);
          }
          else {
            ppiStack136 = (int **)PyNumber_InPlaceAdd(ppiStack152,piVar7);
            *ppiStack152 = (int *)((int)*ppiStack152 + -1);
            if (*ppiStack152 == (int *)0x0) {
              (*(code *)ppiStack152[1][6])(ppiStack152);
            }
          }
          *piVar7 = *piVar7 + -1;
          opcode = ppiStack136;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
            opcode = ppiStack136;
          }
          goto LAB_101b9b8e;
        case (int **)0x38:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x50,4,&DAT_10364f5c);
          break;
        case (int **)0x39:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_InPlaceMultiply(ppiStack152,oparg_var14);
          break;
        case (int **)0x3b:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x58,0xc,&DAT_10364f74);
          break;
        case (int **)0x3c:
          ppiStack144 = (int **)ppiVar16[-1];
          piVar7 = ppiVar16[-2];
          ppiVar13 = ppiVar16 + -3;
          ppiStack152 = (int **)*ppiVar13;
          local_8c = ppiVar13;
          ppiStack136 = (int **)PyObject_SetItem(piVar7,ppiStack144,ppiStack152);
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          *ppiStack144 = (int *)((int)*ppiStack144 + -1);
          opcode = ppiStack136;
          if (*ppiStack144 == (int *)0x0) {
            (*(code *)ppiStack144[1][6])(ppiStack144);
            opcode = ppiStack136;
          }
          goto joined_r0x101baa38;
        case (int **)0x3d:
          piVar7 = ppiVar16[-1];
          local_8c = ppiVar16 + -2;
          ppiStack152 = (int **)*local_8c;
          ppiStack144 = (int **)PyObject_DelItem(ppiStack152,piVar7);
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          goto LAB_101ba466;
        case (int **)0x3e:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_Lshift(ppiStack152,oparg_var14);
          break;
        case (int **)0x3f:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e6f30(0x30,&DAT_10364ee0);
          break;
        case (int **)0x40:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_And(ppiStack152,oparg_var14);
          break;
        case (int **)0x41:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_Xor(ppiStack152,oparg_var14);
          break;
        case (int **)0x42:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)PyNumber_Or(ppiStack152,oparg_var14);
          break;
        case (int **)0x43:
          piVar7 = ppiVar16[-2];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)*local_8c;
          if ((*(int *)(piVar7[1] + 0x30) == 0) ||
             (*(int *)(*(int *)(piVar7[1] + 0x30) + 0x5c) == 0)) {
            ppiStack136 = (int **)FUN_100e6ff0(&_Py_NoneStruct,0x14,puVar12);
          }
          else {
            ppiStack136 = (int **)FUN_100e6ff0(&_Py_NoneStruct,0x5c,puVar12);
          }
LAB_101b9ed5:
          ppiVar16 = ppiVar16 + -1;
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          opcode = ppiStack136;
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
            opcode = ppiStack136;
          }
          goto LAB_101b9b8e;
        case (int **)0x44:
          piVar7 = ppiVar16[-1];
          ppiStack152 = (int **)PyObject_GetIter(piVar7);
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          *(int ***)(ppiVar16 + -1) = ppiStack152;
          param_1 = local_a0;
          if (ppiStack152 == (int **)0x0) goto LAB_101b869b;
          uVar5 = *(ushort *)local_94;
          if ((uVar5 & 0xff) == 0x5d) {
            oparg = (int **)(uint)(uVar5 >> 8);
            local_94 = (int *)((ushort *)local_94 + 1);
            goto opcode_switch_caseD_5d;
          }
          piVar7 = local_a0;
          if ((uVar5 & 0xff) == 0x83) {
            oparg_var14 = (int **)(uint)(uVar5 >> 8);
            local_94 = (int *)((ushort *)local_94 + 1);
            goto opcode_switch_caseD_83;
          }
          goto LAB_101b8915;
        case (int **)0x45:
          piVar7 = ppiVar16[-1];
          if ((undefined *)piVar7[1] != &PyCoro_Type) {
            if ((undefined *)piVar7[1] == &PyGen_Type) goto LAB_101b9610;
            ppiStack152 = (int **)PyObject_GetIter(piVar7);
            *piVar7 = *piVar7 + -1;
            if (*piVar7 == 0) {
              (**(code **)(piVar7[1] + 0x18))(piVar7);
            }
            *(int ***)(ppiVar16 + -1) = ppiStack152;
            opcode = ppiStack152;
            goto LAB_101b9605;
          }
          if ((*(uint *)(local_74 + 0x1c) & 0x180) != 0) goto LAB_101b9610;
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (*pcRam103a3560)(piVar7);
          }
          ppiVar16[-1] = (int *)0x0;
          _PyErr_SetString(local_9c,PyExc_TypeError,
                           "cannot \'yield from\' a coroutine object in a non-coroutine generator");
          param_1 = local_a0;
          goto LAB_101b869b;
        case (int **)0x46:
          ppiVar13 = ppiVar16 + -1;
          opcode = (int **)*ppiVar13;
          local_8c = ppiVar13;
          if ((DAT_103b673c[2][0xb] == 0) ||
             (iVar6 = _PyDict_GetItemId(DAT_103b673c[2][0xb],&DAT_103b4e8c), iVar6 == 0)) {
            _PyErr_SetString(local_9c,PyExc_RuntimeError,"lost sys.displayhook");
            ppiVar16 = ppiVar13;
            goto LAB_101b8a45;
          }
          ppiStack152 = (int **)PyObject_CallFunctionObjArgs(iVar6,opcode,0);
          *opcode = (int *)((int)*opcode + -1);
          if (*opcode == (int *)0x0) {
            (*(code *)opcode[1][6])(opcode);
          }
          opcode = ppiStack152;
          param_1 = local_a0;
          piVar7 = local_a0;
          if (ppiStack152 != (int **)0x0) goto LAB_101ba4f4;
          goto LAB_101b869b;
        case (int **)0x47:
          if (*(undefined **)(local_a0[5] + 4) == &PyDict_Type) {
            piVar15 = (int *)_PyDict_GetItemIdWithError(local_a0[5],&DAT_103b4ed4);
            if (piVar15 != (int *)0x0) {
              *piVar15 = *piVar15 + 1;
              *ppiVar16 = piVar15;
              ppiVar13 = ppiVar16 + 1;
              local_8c = ppiVar16 + 1;
              goto LAB_101b8915;
            }
            if (local_9c[0xd] != (int *)0x0) goto LAB_101b869b;
            pcVar22 = "__build_class__ not found";
            puVar20 = PyExc_NameError;
            goto LAB_101b868f;
          }
          pcVar22 = PTR_s___build_class___103b4ed8;
          if (DAT_103b4edc != 0) goto LAB_101ba8d5;
          do {
            cVar2 = *pcVar22;
            pcVar22 = pcVar22 + 1;
          } while (cVar2 != '\0');
          DAT_103b4edc = FUN_10175160(PTR_s___build_class___103b4ed8,0,0);
          piVar7 = local_a0;
          param_1 = piVar7;
          if (DAT_103b4edc == 0) goto LAB_101b869b;
          PyUnicode_InternInPlace(&DAT_103b4edc);
          _DAT_103b4ed4 = DAT_103c79b8;
          DAT_103c79b8 = &DAT_103b4ed4;
          if (DAT_103b4edc == 0) goto LAB_101b869b;
LAB_101ba8d5:
          piVar15 = (int *)PyObject_GetItem(piVar7[5],DAT_103b4edc);
          if (piVar15 == (int *)0x0) {
            iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_KeyError);
            param_1 = piVar7;
            if (iVar6 != 0) {
              pcVar22 = "__build_class__ not found";
              puVar20 = PyExc_NameError;
LAB_101b868f:
              _PyErr_SetString(local_9c,puVar20,pcVar22);
              param_1 = piVar7;
            }
            goto LAB_101b869b;
          }
          *ppiVar16 = piVar15;
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar16 + 1;
          goto LAB_101b8915;
        case (int **)0x48:
          ppiStack152 = (int **)ppiVar16[-2];
          ppiVar13 = ppiVar16 + -1;
          piVar7 = ppiStack152[1];
          piVar15 = *ppiVar13;
          local_8c = ppiVar13;
          if ((piVar7 == (int *)&PyGen_Type) || (piVar7 == (int *)&PyCoro_Type)) {
            local_70 = (int *)FUN_10122710(0,0);
          }
          else {
            if (piVar15 == &_Py_NoneStruct) {
              local_70 = (int *)(*(code *)piVar7[0x1c])(ppiStack152);
            }
            else {
              local_70 = (int *)_PyObject_CallMethodIdObjArgs(ppiStack152,&DAT_103b4eec,piVar15,0);
            }
          }
          *piVar15 = *piVar15 + -1;
          if (*piVar15 == 0) {
            (**(code **)(piVar15[1] + 0x18))(piVar15);
          }
          param_1 = local_a0;
          if (local_70 != (int *)0x0) {
            local_a0[0xd] = local_a0[0xd] + -2;
            *(int ***)(local_a0 + 9) = ppiVar13;
            goto LAB_101bc6ce;
          }
          if ((local_9c[10] != (int *)0x0) &&
             (iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_StopIteration),
             param_1 = local_a0, iVar6 != 0)) {
            FUN_101be030(local_9c,local_a0);
          }
          iVar6 = _PyGen_FetchStopIterationValue(&piStack60);
          if (iVar6 < 0) goto LAB_101b869b;
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          ppiVar16[-2] = piStack60;
          piVar7 = param_1;
          goto LAB_101b8915;
        case (int **)0x49:
opcode_switch_caseD_49:
          oparg = (int **)ppiVar16[-1];
          opcode = (int **)FUN_10123660();
          if (opcode == (int **)0x0) {
            ppiStack136 = (int **)oparg[1];
            if ((ppiStack136[10] == (int *)0x0) || (*ppiStack136[10] == 0)) {
              if ((((ushort *)local_94)[-2] & 0xff) == 0x34) {
                piVar7 = ppiStack136[3];
                pcVar22 = 
                "\'async with\' received an object from __aenter__ that does not implement__await__: %.100s"
                ;
              }
              else {
                if ((((ushort *)local_94)[-2] & 0xff) != 0x51) goto LAB_101b95b7;
                piVar7 = ppiStack136[3];
                pcVar22 = 
                "\'async with\' received an object from __aexit__ that does not implement__await__: %.100s"
                ;
              }
              _PyErr_Format(local_9c,PyExc_TypeError,pcVar22,piVar7);
            }
          }
LAB_101b95b7:
          *oparg = (int *)((int)*oparg + -1);
          if (*oparg == (int *)0x0) {
            (*(code *)oparg[1][6])(oparg);
          }
          if ((((opcode == (int **)0x0) || (opcode[1] != (int *)&PyCoro_Type)) ||
              (piVar7 = opcode[2], piVar7 == (int *)0x0)) || (piVar7[9] == 0)) {
            *(int ***)(ppiVar16 + -1) = opcode;
LAB_101b9605:
            ppiVar13 = ppiVar16;
            param_1 = local_a0;
            if (opcode == (int **)0x0) goto LAB_101b869b;
          }
          else {
            if ((-1 < piVar7[0xd]) &&
               (*(char *)(*(int *)(piVar7[4] + 0x24) + 0x12 + piVar7[0xd]) == 'H')) {
              piVar7 = *(int **)(piVar7[9] + -4);
              iVar6 = *piVar7;
              *piVar7 = iVar6;
              if (iVar6 == 0) {
                (**(code **)(piVar7[1] + 0x18))(piVar7);
              }
              FUN_101b7050(opcode);
              _PyErr_SetString(local_9c,PyExc_RuntimeError,"coroutine is being awaited already");
LAB_101bc146:
              ppiVar16[-1] = (int *)0x0;
              ppiVar13 = ppiVar16;
              param_1 = local_a0;
              goto LAB_101b869b;
            }
            *(int ***)(ppiVar16 + -1) = opcode;
          }
LAB_101b9610:
          ppiVar13 = ppiVar16;
          piVar7 = local_a0;
          if ((char)*(ushort *)local_94 != 'd') goto LAB_101b8915;
          oparg_var14 = (int **)(uint)(*(ushort *)local_94 >> 8);
          puVar12 = (ushort *)local_94 + 1;
opcode_switch_caseD_64:
          piVar7 = *(int **)(local_44 + 0xc + (int)oparg_var14 * 4);
          *piVar7 = *piVar7 + 1;
          *ppiVar16 = piVar7;
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar16 + 1;
          goto LAB_101b8a90;
        case (int **)0x4b:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x60,0x2c,&DAT_10364f54);
          break;
        case (int **)0x4c:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(100,0x30,&DAT_10364f58);
          break;
        case (int **)0x4d:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x68,0x34,&DAT_10364f50);
          break;
        case (int **)0x4e:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x6c,0x38,&DAT_10364f4c);
          break;
        case (int **)0x4f:
          oparg_var14 = (int **)ppiVar16[-1];
          local_8c = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          ppiStack144 = (int **)FUN_100e77b0(0x70,0x3c,&DAT_10364f48);
          break;
        case (int **)0x51:
          piVar7 = ppiVar16[-1];
          piStack36 = &_Py_NoneStruct;
          ppiStack136 = (int **)&_Py_NoneStruct;
          if (piVar7 == (int *)0x0) {
            ppiStack128 = (int **)ppiVar16[-2];
            ppiVar16[-2] = (int *)0x0;
            piVar7 = &_Py_NoneStruct;
            ppiVar13 = ppiVar16 + -1;
          }
          else {
            ppiStack136 = (int **)ppiVar16[-2];
            ppiStack128 = (int **)ppiVar16[-7];
            piStack36 = ppiVar16[-3];
            ppiVar16[-7] = ppiVar16[-6];
            ppiVar16[-6] = ppiVar16[-5];
            ppiVar16[-5] = ppiVar16[-4];
            ppiVar16[-4] = (int *)0x0;
            local_a0[local_a0[0xf] * 3 + 0x10] = local_a0[local_a0[0xf] * 3 + 0x10] + -1;
          }
          ppiStack40 = ppiStack136;
          piStack44 = piVar7;
          ppiStack152 = (int **)FUN_101b70d0(3,0);
          *ppiStack128 = (int *)((int)*ppiStack128 + -1);
          if (*ppiStack128 == (int *)0x0) {
            (*(code *)ppiStack128[1][6])(ppiStack128);
          }
          param_1 = local_a0;
          if (ppiStack152 == (int **)0x0) goto LAB_101b869b;
          *piVar7 = *piVar7 + 1;
          *ppiVar13 = piVar7;
          *(int ***)(ppiVar13 + 1) = ppiStack152;
          ppiVar16 = ppiVar13 + 2;
          ppiVar13 = ppiVar16;
          piVar7 = local_a0;
          local_8c = ppiVar16;
          if (*(char *)local_94 == 'R') {
            local_94 = (int *)((ushort *)local_94 + 1);
            goto opcode_switch_caseD_52;
          }
          goto LAB_101b8915;
        case (int **)0x52:
opcode_switch_caseD_52:
          piVar7 = ppiVar16[-1];
          ppiVar13 = ppiVar16 + -2;
          ppiStack152 = (int **)*ppiVar13;
          local_8c = ppiVar13;
          if (ppiStack152 == (int **)&_Py_NoneStruct) {
            ppiStack136 = (int **)0x0;
          }
          else {
            ppiStack136 = (int **)PyObject_IsTrue(piVar7);
          }
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          param_1 = local_a0;
          if ((int)ppiStack136 < 0) goto LAB_101b869b;
          ppiVar16 = ppiVar13;
          if ((int)ppiStack136 < 1) goto LAB_101b9850;
          if (local_a0[0xf] < 1) goto LAB_101bc7e2;
          iVar6 = local_a0[0xf] + -1;
          local_a0[0xf] = iVar6;
          piVar7 = local_a0 + iVar6 * 3;
          piVar15 = local_a0;
          if (piVar7[0x13] + 3 < (int)((int)ppiVar13 - local_a0[8]) >> 2) {
            do {
              piVar21 = ppiVar13[-1];
              ppiVar13 = ppiVar13 + -1;
              if ((piVar21 != (int *)0x0) && (*piVar21 = *piVar21 + -1, *piVar21 == 0)) {
                (**(code **)(piVar21[1] + 0x18))(piVar21);
                piVar15 = local_a0;
              }
            } while (piVar7[0x13] + 3 < (int)((int)ppiVar13 - piVar15[8]) >> 2);
          }
          opcode = (int **)local_9c[0x14];
          ppiStack152 = (int **)opcode[2];
          piVar7 = *opcode;
          piVar15 = opcode[1];
          ppiStack144 = ppiVar13 + -2;
          *opcode = ppiVar13[-1];
          opcode[1] = *ppiStack144;
          opcode[2] = ppiVar13[-3];
          if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
            (**(code **)(piVar15[1] + 0x18))(piVar15);
          }
          if ((ppiStack152 != (int **)0x0) &&
             (*ppiStack152 = (int *)((int)*ppiStack152 + -1), *ppiStack152 == (int *)0x0)) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          ppiVar13[-3] = (int *)0x0;
          local_8c = ppiStack144;
          ppiVar16 = ppiStack144;
LAB_101b9850:
          ppiVar13 = ppiVar16;
          piVar7 = local_a0;
          if (*(char *)local_94 != 'X') goto LAB_101b8915;
          puVar12 = (ushort *)local_94 + 1;
opcode_switch_caseD_58:
          opcode = (int **)ppiVar16[-1];
          ppiVar16 = ppiVar16 + -1;
          ppiVar13 = ppiVar16;
          local_8c = ppiVar16;
          if (opcode != (int **)0x0) {
            if (opcode[1] != (int *)&PyLong_Type) goto LAB_101b8e7b;
            ppiStack136 = (int **)PyLong_AsLongAndOverflow(opcode,&iStack64);
            if (iStack64 != 0) {
              _PyErr_SetString(DAT_103b673c,PyExc_OverflowError,
                               "Python int too large to convert to C int");
              ppiStack136 = (int **)0xffffffff;
            }
            *opcode = (int *)((int)*opcode + -1);
            if (*opcode == (int *)0x0) {
              (*(code *)opcode[1][6])(opcode);
            }
            opcode = ppiStack136;
            if (ppiStack136 == (int **)0xffffffff) {
              uVar19 = FUN_101b71f0();
              opcode = (int **)((ulonglong)uVar19 >> 0x20);
              param_1 = local_a0;
              if ((int)uVar19 != 0) goto LAB_101b869b;
            }
            puVar12 = (ushort *)((int)local_7c + ((uint)opcode & 0xfffffffe));
          }
          goto LAB_101b8a90;
        case (int **)0x53:
          local_70 = ppiVar16[-1];
          ppiVar13 = ppiVar16 + -1;
          param_1 = local_a0;
          goto LAB_101bc697;
        case (int **)0x54:
          opcode = (int **)ppiVar16[-1];
          ppiVar13 = ppiVar16 + -1;
          local_8c = ppiVar13;
          iVar6 = PyFrame_FastToLocalsWithError(local_a0);
          ppiVar16 = ppiVar13;
          if (-1 < iVar6) {
            if (local_a0[7] != 0) {
              ppiStack152 = (int **)FUN_101bf4a0(opcode);
              PyFrame_LocalsToFast(local_a0,0);
              *opcode = (int *)((int)*opcode + -1);
              if (*opcode == (int *)0x0) {
                (*(code *)opcode[1][6])(opcode);
              }
              bVar18 = ppiStack152 == (int **)0x0;
              goto LAB_101ba47c;
            }
            _PyErr_SetString(local_9c,PyExc_SystemError,"no locals found during \'import *\'");
          }
          goto LAB_101b8a45;
        case (int **)0x55:
          iVar6 = local_a0[7];
          if (iVar6 == 0) {
            _PyErr_Format(local_9c,PyExc_SystemError,"no locals found when setting up annotations");
            goto LAB_101b869b;
          }
          if (*(undefined **)(iVar6 + 4) != &PyDict_Type) {
            ppiStack152 = (int **)_PyUnicode_FromId(&DAT_103b4e74);
            if (ppiStack152 != (int **)0x0) {
              opcode = (int **)PyObject_GetItem(piVar7[7],ppiStack152);
              if (opcode != (int **)0x0) goto LAB_101ba4f4;
              iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_KeyError);
              if (iVar6 != 0) {
                _PyErr_Clear(local_9c);
                _DAT_103b30f4 = _DAT_103b30f4 + 1;
                piVar7 = (int *)FUN_1010c4d0();
                param_1 = local_a0;
                if (piVar7 != (int *)0x0) {
                  ppiStack152 = (int **)PyObject_SetItem(local_a0[7],ppiStack152,piVar7);
                  goto LAB_101bab09;
                }
              }
            }
            goto LAB_101b869b;
          }
          iVar6 = _PyDict_GetItemIdWithError(iVar6);
          if (iVar6 != 0) goto LAB_101b8915;
          if (local_9c[0xd] != (int *)0x0) goto LAB_101b869b;
          _DAT_103b30f4 = _DAT_103b30f4 + 1;
          piVar7 = (int *)FUN_1010c4d0();
          param_1 = local_a0;
          if (piVar7 == (int *)0x0) goto LAB_101b869b;
          ppiStack152 = (int **)_PyDict_SetItemId(local_a0[7],&DAT_103b4e74,piVar7);
          *piVar7 = *piVar7 + -1;
          opcode = ppiStack152;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
            opcode = ppiStack152;
          }
          goto joined_r0x101baa38;
        case (int **)0x56:
          ppiVar13 = ppiVar16 + -1;
          piVar7 = *ppiVar13;
          if ((*(uint *)(local_74 + 0x1c) & 0x200) != 0) {
            local_70 = piVar7;
            if (DAT_103ba058 == 0) {
              piVar7 = (int *)FUN_100760c0();
              if (piVar7 != (int *)0x0) {
                piVar7[1] = 0x103a38b0;
                if ((_DAT_103a3904 & 0x200) != 0) {
                  __PyAsyncGenWrappedValue_Type = __PyAsyncGenWrappedValue_Type + 1;
                }
                goto LAB_101bc59f;
              }
              piVar7 = (int *)0x0;
            }
            else {
              DAT_103ba058 = DAT_103ba058 + -1;
              piVar7 = *(int **)(&DAT_103ba060 + DAT_103ba058 * 4);
LAB_101bc59f:
              if (_DAT_103a515c != 0) {
                _PyTraceMalloc_NewReference(piVar7);
              }
              piVar15 = piVar7 + -2;
              *piVar7 = 1;
              *(int **)(piVar7 + 2) = local_70;
              *local_70 = *local_70 + 1;
              opcode = *(int ***)(DAT_103b6570 + 4);
              *opcode = piVar15;
              piVar7[-1] = piVar7[-1] & 3U | (uint)opcode;
              *piVar15 = DAT_103b6570;
              *(int **)(DAT_103b6570 + 4) = piVar15;
            }
            *local_70 = *local_70 + -1;
            if (*local_70 == 0) {
              (**(code **)(local_70[1] + 0x18))(local_70);
            }
            param_1 = local_a0;
            local_70 = piVar7;
            if (piVar7 == (int *)0x0) goto LAB_101b869b;
          }
          *(int ***)(local_a0 + 9) = ppiVar13;
          param_1 = local_a0;
          local_70 = piVar7;
          goto LAB_101bc6ce;
        case (int **)0x57:
          goto opcode_switch_caseD_57;
        case (int **)0x58:
          goto opcode_switch_caseD_58;
        case (int **)0x59:
          if (local_a0[0xf] < 1) goto LAB_101bc7e2;
          iVar6 = local_a0[0xf] + -1;
          local_a0[0xf] = iVar6;
          if (local_a0[iVar6 * 3 + 0x11] != 0x101) {
            pcVar22 = "popped block is not an except handler";
            puVar20 = PyExc_SystemError;
            goto LAB_101b868f;
          }
          opcode = (int **)local_9c[0x14];
          ppiStack152 = (int **)opcode[2];
          piVar7 = *opcode;
          piVar15 = opcode[1];
          *opcode = ppiVar16[-1];
          ppiVar13 = ppiVar16 + -3;
          opcode[1] = ppiVar16[-2];
          opcode[2] = *ppiVar13;
          local_8c = ppiVar13;
          if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
            (**(code **)(piVar15[1] + 0x18))(piVar15);
          }
          opcode = ppiStack152;
          piVar7 = local_a0;
          if (ppiStack152 != (int **)0x0) goto LAB_101ba4f4;
          goto LAB_101b8915;
        case (int **)0x5a:
          ppiVar13 = ppiVar16 + -1;
          iVar6 = *(int *)(local_6c + 0xc + (int)oparg_var14 * 4);
          opcode = (int **)*ppiVar13;
          ppiStack136 = (int **)local_a0[7];
          local_8c = ppiVar13;
          ppiStack120 = opcode;
          if (ppiStack136 == (int **)0x0) {
            _PyErr_Format(local_9c,PyExc_SystemError,"no locals found when storing %R",iVar6);
            ppiVar16 = ppiVar13;
            goto LAB_101b8a45;
          }
          piVar7 = ppiStack136[1];
          if (piVar7 == (int *)&PyDict_Type) {
            opcode = (int **)PyDict_SetItem(ppiStack136,iVar6,opcode);
          }
          else {
            if ((iVar6 == 0) || (opcode == (int **)0x0)) {
              if ((DAT_103b673c == (int **)0x0) || (DAT_103b673c[0xd] == (int *)0x0)) {
                _PyErr_SetString(DAT_103b673c,PyExc_SystemError,"null argument to internal routine")
                ;
              }
              goto LAB_101baa1a;
            }
            if ((piVar7[0xe] == 0) ||
               (ppiStack152 = *(int ***)(piVar7[0xe] + 8), ppiStack152 == (int **)0x0)) {
              ppiStack152 = (int **)piVar7[0xd];
              if (ppiStack152 == (int **)0x0) {
LAB_101ba9e5:
                FUN_100e59e0();
              }
              else {
                iVar11 = *(int *)(*(int *)(iVar6 + 4) + 0x30);
                if ((iVar11 == 0) || (*(int *)(iVar11 + 0x84) == 0)) {
                  if (ppiStack152[5] == (int *)0x0) goto LAB_101ba9e5;
                  FUN_100e59e0();
                }
                else {
                  ppiStack152 = (int **)PyNumber_AsSsize_t(iVar6,PyExc_IndexError);
                  if ((ppiStack152 != (int **)0xffffffff) || (iVar6 = PyErr_Occurred(), iVar6 == 0))
                  {
                    opcode = (int **)PySequence_SetItem(ppiStack136,ppiStack152,opcode);
                    goto LAB_101baa1d;
                  }
                }
              }
LAB_101baa1a:
              opcode = (int **)0xffffffff;
            }
            else {
              opcode = (int **)(*(code *)ppiStack152)(ppiStack136,iVar6,opcode);
            }
          }
LAB_101baa1d:
          *ppiStack120 = (int *)((int)*ppiStack120 + -1);
          if (*ppiStack120 == (int *)0x0) {
            (*(code *)ppiStack120[1][6])(ppiStack120);
          }
          goto joined_r0x101baa38;
        case (int **)0x5b:
          iVar6 = *(int *)(local_6c + 0xc + (int)oparg_var14 * 4);
          if (local_a0[7] != 0) {
            iVar11 = PyObject_DelItem(local_a0[7]);
            piVar7 = local_a0;
            if (iVar11 != 0) goto LAB_101bab89;
            goto LAB_101b8915;
          }
          pcVar22 = "no locals when deleting %R";
LAB_101bc28f:
          _PyErr_Format(local_9c,PyExc_SystemError,pcVar22,iVar6);
          param_1 = local_a0;
          goto LAB_101b869b;
        case (int **)0x5c:
opcode_switch_caseD_5c:
          ppiStack136 = (int **)ppiVar16[-1];
          ppiVar16 = ppiVar16 + -1;
          opcode = ppiStack136;
          if ((ppiStack136[1] == (int *)&PyTuple_Type) && ((int **)ppiStack136[2] == oparg_var14))
          goto joined_r0x101b9a12;
          if ((ppiStack136[1] == (int *)&PyList_Type) && ((int **)ppiStack136[2] == oparg_var14)) {
            piVar7 = ppiStack136[3];
            while (ppiVar4 = ppiVar16, oparg_var14 != (int **)0x0) {
              piVar15 = (int *)piVar7[(int)oparg_var14 + -1];
              oparg_var14 = (int **)((int)oparg_var14 + -1);
              *piVar15 = *piVar15 + 1;
              *ppiVar16 = piVar15;
              ppiVar16 = ppiVar16 + 1;
            }
            goto LAB_101bbaab;
          }
          local_8c = ppiVar16;
          iVar6 = FUN_101bdd80(oparg_var14,0xffffffff,ppiVar16 + (int)oparg_var14);
          opcode = ppiStack136;
          param_1 = local_a0;
          ppiVar4 = ppiVar16 + (int)oparg_var14;
          if (iVar6 == 0) goto LAB_101bc1a8;
          goto LAB_101bbaab;
        case (int **)0x5d:
opcode_switch_caseD_5d:
          piVar7 = ppiVar16[-1];
          ppiStack152 = ppiVar16 + -1;
          piVar15 = (int *)(**(code **)(piVar7[1] + 0x70))(piVar7);
          if (piVar15 != (int *)0x0) {
            *ppiVar16 = piVar15;
            ppiVar16 = ppiVar16 + 1;
            uVar5 = *(ushort *)local_94;
            if ((uVar5 & 0xff) == 0x7d) {
              oparg_var14 = (int **)(uint)(uVar5 >> 8);
              local_94 = (int *)((ushort *)local_94 + 1);
              goto opcode_switch_caseD_7d;
            }
            ppiVar13 = ppiVar16;
            piVar7 = local_a0;
            local_8c = ppiVar16;
            if ((uVar5 & 0xff) == 0x5c) {
              oparg_var14 = (int **)(uint)(uVar5 >> 8);
              local_94 = (int *)((ushort *)local_94 + 1);
              goto opcode_switch_caseD_5c;
            }
            goto LAB_101b8915;
          }
          if (local_9c[0xd] != (int *)0x0) {
            iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_StopIteration);
            opcode = local_9c;
            param_1 = local_a0;
            if (iVar6 == 0) goto LAB_101b869b;
            if (local_9c[10] != (int *)0x0) {
              FUN_101be030(local_9c,local_a0);
            }
            _PyErr_Clear(opcode);
          }
          ppiVar16 = ppiStack152;
          *piVar7 = *piVar7 + -1;
          local_8c = ppiStack152;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          pcVar22 = (char *)((int)local_94 + ((uint)oparg & 0xfffffffe));
          local_94 = (int *)((int)local_94 + ((uint)oparg & 0xfffffffe));
          ppiVar13 = ppiVar16;
          piVar7 = local_a0;
          if (*pcVar22 != 'W') goto LAB_101b8915;
          puVar12 = (ushort *)local_94 + 1;
opcode_switch_caseD_57:
          local_94 = (int *)puVar12;
          if (local_a0[0xf] < 1) goto LAB_101bc7e2;
          local_a0[0xf] = local_a0[0xf] + -1;
          ppiVar13 = ppiVar16;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x5e:
          opcode = (int **)ppiVar16[-1];
          ppiStack152 = ppiVar16 + -1 + ((uint)oparg_var14 & 0xff) + 1 + ((int)oparg_var14 >> 8);
          iVar6 = FUN_101bdd80((uint)oparg_var14 & 0xff,(int)oparg_var14 >> 8,ppiStack152);
          ppiVar16 = ppiVar16 + -1;
          ppiVar4 = ppiStack152;
          if (iVar6 == 0) goto LAB_101b8a45;
          goto LAB_101bbaab;
        case (int **)0x5f:
          piVar7 = ppiVar16[-1];
          local_8c = ppiVar16 + -2;
          ppiStack152 = (int **)*local_8c;
          ppiStack144 = (int **)PyObject_SetAttr(piVar7,*(undefined4 *)
                                                         (local_6c + 0xc + (int)oparg_var14 * 4),
                                                 ppiStack152);
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
LAB_101ba466:
          ppiVar13 = ppiVar16 + -2;
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          bVar18 = ppiStack144 == (int **)0x0;
LAB_101ba47c:
          param_1 = local_a0;
          piVar7 = local_a0;
          if (!bVar18) goto LAB_101b869b;
          goto LAB_101b8915;
        case (int **)0x60:
          ppiVar13 = ppiVar16 + -1;
          piVar7 = *ppiVar13;
          local_8c = ppiVar13;
          ppiStack152 = (int **)PyObject_SetAttr(piVar7,*(undefined4 *)
                                                         (local_6c + 0xc + (int)oparg_var14 * 4),0);
          goto LAB_101bab09;
        case (int **)0x61:
          ppiVar13 = ppiVar16 + -1;
          piVar7 = *ppiVar13;
          local_8c = ppiVar13;
          ppiStack152 = (int **)PyDict_SetItem(local_a0[6],
                                               *(undefined4 *)(local_6c + 0xc + (int)oparg_var14 * 4),
                                               piVar7);
LAB_101bab09:
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          bVar18 = ppiStack152 == (int **)0x0;
          goto LAB_101ba47c;
        case (int **)0x62:
          iVar6 = *(int *)(local_6c + 0xc + (int)oparg_var14 * 4);
          iVar11 = PyDict_DelItem(local_a0[6],iVar6);
          piVar7 = local_a0;
          if (iVar11 != 0) goto LAB_101bab6c;
          goto LAB_101b8915;
        case (int **)0x64:
          goto opcode_switch_caseD_64;
        case (int **)0x65:
          iVar6 = *(int *)(local_6c + 0xc + (int)oparg_var14 * 4);
          iVar11 = local_a0[7];
          if (iVar11 == 0) {
            pcVar22 = "no locals when loading %R";
            goto LAB_101bc28f;
          }
          if (*(undefined **)(iVar11 + 4) == &PyDict_Type) {
            piVar7 = (int *)PyDict_GetItemWithError();
            if (piVar7 != (int *)0x0) {
              *piVar7 = *piVar7 + 1;
              *ppiVar16 = piVar7;
              local_8c = ppiVar16 + 1;
              ppiVar13 = local_8c;
              piVar7 = local_a0;
              goto LAB_101b8915;
            }
            param_1 = local_a0;
            if (local_9c[0xd] != (int *)0x0) goto LAB_101b869b;
          }
          else {
            opcode = (int **)PyObject_GetItem(iVar11,iVar6);
            if (opcode != (int **)0x0) goto LAB_101bbc5b;
            iVar11 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_KeyError);
            param_1 = local_a0;
            if (iVar11 == 0) goto LAB_101b869b;
            _PyErr_Clear(local_9c);
          }
          piVar7 = (int *)PyDict_GetItemWithError(local_a0[6],iVar6);
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar7 + 1;
            *ppiVar16 = piVar7;
            local_8c = ppiVar16 + 1;
            ppiVar13 = local_8c;
            piVar7 = local_a0;
            goto LAB_101b8915;
          }
          param_1 = local_a0;
          if (local_9c[0xd] != (int *)0x0) goto LAB_101b869b;
          if (*(undefined **)(local_a0[5] + 4) != &PyDict_Type) {
            piVar7 = (int *)PyObject_GetItem(local_a0[5],iVar6);
            if (piVar7 != (int *)0x0) {
              *ppiVar16 = piVar7;
              local_8c = ppiVar16 + 1;
              ppiVar13 = local_8c;
              piVar7 = local_a0;
              goto LAB_101b8915;
            }
LAB_101bab6c:
            iVar11 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_KeyError);
            param_1 = local_a0;
            if (iVar11 != 0) {
LAB_101bab89:
              ppiStack152 = (int **)PyExc_NameError;
              param_1 = local_a0;
              if ((iVar6 != 0) &&
                 (iVar6 = PyUnicode_AsUTF8AndSize(iVar6,0), param_1 = local_a0, iVar6 != 0)) {
                _PyErr_Format(local_9c,ppiStack152,"name \'%.200s\' is not defined",iVar6);
              }
            }
            goto LAB_101b869b;
          }
          piVar7 = (int *)PyDict_GetItemWithError();
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar7 + 1;
            *ppiVar16 = piVar7;
            local_8c = ppiVar16 + 1;
            ppiVar13 = local_8c;
            piVar7 = local_a0;
            goto LAB_101b8915;
          }
          param_1 = local_a0;
          if (local_9c[0xd] == (int *)0x0) {
            ppiStack152 = (int **)PyExc_NameError;
            if ((iVar6 != 0) &&
               (iVar6 = PyUnicode_AsUTF8AndSize(iVar6,0), param_1 = local_a0, iVar6 != 0)) {
              _PyErr_Format(local_9c,ppiStack152,"name \'%.200s\' is not defined",iVar6);
            }
          }
          goto LAB_101b869b;
        case (int **)0x66:
          opcode = (int **)PyTuple_New(oparg_var14);
          param_1 = local_a0;
          if (opcode == (int **)0x0) goto LAB_101b869b;
          iVar6 = (int)oparg + -1;
          if (iVar6 < 0) goto LAB_101bbeb0;
          ppiVar13 = opcode + (int)oparg + 2;
          do {
            local_8c = ppiVar16;
            *ppiVar13 = local_8c[-1];
            iVar6 = iVar6 + -1;
            ppiVar13 = ppiVar13 + -1;
            ppiVar16 = local_8c + -1;
          } while (-1 < iVar6);
          *(int ***)(local_8c + -1) = opcode;
          ppiVar13 = local_8c;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x67:
          opcode = (int **)PyList_New(oparg_var14);
          param_1 = local_a0;
          if (opcode == (int **)0x0) goto LAB_101b869b;
          iVar6 = (int)oparg + -1;
          if (iVar6 < 0) goto LAB_101bbeb0;
          do {
            local_8c = ppiVar16;
            ppiVar16 = local_8c + -1;
            *(int **)(opcode[3] + iVar6) = *ppiVar16;
            iVar6 = iVar6 + -1;
          } while (-1 < iVar6);
          *(int ***)ppiVar16 = opcode;
          ppiVar13 = local_8c;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x68:
          ppiStack144 = (int **)PySet_New(0);
          ppiStack136 = (int **)0x0;
          param_1 = local_a0;
          if (ppiStack144 == (int **)0x0) goto LAB_101b869b;
          ppiStack128 = oparg;
          opcode = ppiStack136;
          if (0 < (int)oparg) {
            opcode = (int **)0x0;
            ppiStack120 = ppiVar16 + (int)oparg * 0x3fffffff;
            do {
              piVar7 = *ppiStack120;
              if (opcode == (int **)0x0) {
                opcode = (int **)PySet_Add(ppiStack144,piVar7);
              }
              *piVar7 = *piVar7 + -1;
              if (*piVar7 == 0) {
                (**(code **)(piVar7[1] + 0x18))(piVar7);
              }
              ppiStack128 = (int **)((int)ppiStack128 + -1);
              ppiStack120 = ppiStack120 + 1;
              ppiVar16 = local_8c;
            } while (0 < (int)ppiStack128);
          }
          ppiStack136 = opcode;
          ppiVar16 = ppiVar16 + (int)oparg * 0x3fffffff;
          opcode = ppiStack144;
          if (ppiStack136 != (int **)0x0) goto LAB_101b8a45;
          *(int ***)ppiVar16 = ppiStack144;
          local_8c = ppiVar16 + 1;
          ppiVar13 = local_8c;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x69:
          ppiStack136 = (int **)_PyDict_NewPresized(oparg_var14);
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          ppiStack144 = oparg;
          if ((int)oparg < 1) goto LAB_101bb417;
          ppiVar13 = ppiVar16 + (int)oparg * 0x3ffffffe;
          goto LAB_101bb3e7;
        case (int **)0x6a:
          piVar7 = ppiVar16[-1];
          ppiStack152 = (int **)PyObject_GetAttr(piVar7,*(undefined4 *)
                                                         (local_6c + 0xc + (int)oparg_var14 * 4));
          *piVar7 = *piVar7 + -1;
          opcode = ppiStack152;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
            opcode = ppiStack152;
          }
          goto LAB_101b9b8e;
        case (int **)0x6b:
          oparg = (int **)ppiVar16[-1];
          ppiStack128 = (int **)ppiVar16[-2];
          ppiVar13 = ppiVar16 + -1;
          local_8c = ppiVar13;
          switch(oparg_var14) {
          case (int **)0x6:
            if ((oparg[1][0xd] == 0) ||
               (pcVar9 = *(code **)(oparg[1][0xd] + 0x1c), pcVar9 == (code *)0x0)) {
              uVar17 = _PySequence_IterSearch(oparg,ppiStack128,3);
            }
            else {
              uVar17 = (*pcVar9)(oparg,ppiStack128);
            }
            if (-1 < (int)uVar17) goto LAB_101b9103;
            piVar7 = (int *)0x0;
            goto LAB_101b914a;
          case (int **)0x8:
            uVar17 = (uint)(ppiStack128 == oparg);
            goto LAB_101b9103;
          case (int **)0x9:
            uVar17 = (uint)(ppiStack128 != oparg);
            goto LAB_101b9103;
          case (int **)0xa:
            if ((oparg[1][0x15] & 0x4000000U) != 0) {
              ppiStack152 = (int **)PyTuple_Size(oparg);
              iVar6 = 0;
              if ((int)ppiStack152 < 1) goto LAB_101b90f7;
              opcode = oparg + 3;
              goto LAB_101b90d1;
            }
            if ((-1 < oparg[1][0x15]) || (((uint)oparg[0x15] & 0x40000000) == 0))
            goto LAB_101b9113;
            goto LAB_101b90f7;
          default:
            piVar7 = (int *)PyObject_RichCompare(ppiStack128,oparg,oparg_var14);
            goto LAB_101b914a;
          case (int **)0x7:
            goto switchD_101b9016_caseD_7;
          }
        case (int **)0x6c:
          ppiVar13 = ppiVar16 + -1;
          ppiStack144 = *(int ***)(local_6c + 0xc + (int)oparg_var14 * 4);
          ppiStack120 = (int **)*ppiVar13;
          ppiStack136 = (int **)ppiVar16[-2];
          local_8c = ppiVar13;
          piVar7 = (int *)_PyDict_GetItemIdWithError(local_a0[5],&DAT_103b4e80);
          if (piVar7 == (int *)0x0) {
            if (local_9c[0xd] == (int *)0x0) {
              _PyErr_SetString(local_9c,PyExc_ImportError,"__import__ not found");
            }
            opcode = (int **)0x0;
          }
          else {
            if (piVar7 == (int *)local_9c[2][0x55]) {
              iVar6 = _PyLong_AsInt(ppiStack136);
              if ((iVar6 == -1) && (local_9c[0xd] != (int *)0x0)) {
                opcode = (int **)0x0;
              }
              else {
                puVar8 = (undefined4 *)local_a0[7];
                if (puVar8 == (undefined4 *)0x0) {
                  puVar8 = &_Py_NoneStruct;
                }
                opcode = (int **)PyImport_ImportModuleLevelObject
                                           (ppiStack144,local_a0[6],puVar8,ppiStack120,iVar6);
              }
            }
            else {
              *piVar7 = *piVar7 + 1;
              ppiStack32 = ppiStack144;
              iStack28 = local_a0[6];
              puStack24 = (undefined4 *)local_a0[7];
              if (puStack24 == (undefined4 *)0x0) {
                puStack24 = &_Py_NoneStruct;
              }
              ppiStack20 = ppiStack120;
              ppiStack16 = ppiStack136;
              ppiStack152 = (int **)FUN_101b70d0(5,0);
              *piVar7 = *piVar7 + -1;
              opcode = ppiStack152;
              if (*piVar7 == 0) {
                (**(code **)(piVar7[1] + 0x18))(piVar7);
                opcode = ppiStack152;
              }
            }
          }
          *ppiStack136 = (int *)((int)*ppiStack136 + -1);
          if (*ppiStack136 == (int *)0x0) {
            (*(code *)ppiStack136[1][6])(ppiStack136);
          }
          *ppiStack120 = (int *)((int)*ppiStack120 + -1);
          if (*ppiStack120 == (int *)0x0) {
            (*(code *)ppiStack120[1][6])(ppiStack120);
          }
          *(int ***)(ppiVar16 + -2) = opcode;
          goto joined_r0x101b9c73;
        case (int **)0x6d:
          opcode = (int **)FUN_101bf1c0(*(undefined4 *)(local_6c + 0xc + (int)oparg_var14 * 4));
          *(int ***)ppiVar16 = opcode;
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar13;
          goto joined_r0x101b9c73;
        case (int **)0x6e:
          puVar12 = (ushort *)((int)puVar12 + ((uint)oparg_var14 & 0xfffffffe));
          goto LAB_101b8a90;
        case (int **)0x6f:
          opcode = (int **)ppiVar16[-1];
          ppiStack152 = ppiVar16 + -1;
          if (opcode == (int **)&_Py_TrueStruct) goto LAB_101b8a6d;
          if (opcode == (int **)&_Py_FalseStruct) {
            puVar12 = (ushort *)((int)local_7c + ((uint)oparg_var14 & 0xfffffffe));
            goto LAB_101b8a90;
          }
          iVar6 = PyObject_IsTrue(opcode);
          ppiVar4 = ppiStack152;
          if (0 < iVar6) goto LAB_101bbaab;
          param_1 = local_a0;
          if (iVar6 != 0) goto LAB_101b869b;
          piVar7 = local_a0;
          local_94 = (int *)((int)local_7c + ((uint)oparg & 0xfffffffe));
          goto LAB_101b8915;
        case (int **)0x70:
          opcode = (int **)ppiVar16[-1];
          ppiStack152 = ppiVar16 + -1;
          if (opcode == (int **)&_Py_FalseStruct) {
LAB_101b8a6d:
            ppiStack152 = ppiVar16 + -1;
            local_8c = ppiStack152;
            goto LAB_101b8a73;
          }
          if (opcode == (int **)&_Py_TrueStruct) {
            puVar12 = (ushort *)((int)local_7c + ((uint)oparg_var14 & 0xfffffffe));
            goto LAB_101b8a90;
          }
          iVar6 = PyObject_IsTrue(opcode);
          if (0 < iVar6) {
            piVar7 = local_a0;
            local_94 = (int *)((int)local_7c + ((uint)oparg & 0xfffffffe));
            goto LAB_101b8915;
          }
          param_1 = local_a0;
          ppiVar4 = ppiStack152;
          if (iVar6 != 0) goto LAB_101b869b;
          goto LAB_101bbaab;
        case (int **)0x71:
          goto opcode_switch_caseD_71;
        case (int **)0x72:
          goto opcode_switch_caseD_72;
        case (int **)0x73:
          goto opcode_switch_caseD_73;
        case (int **)0x74:
          ppiStack120 = (int **)local_a0[6];
          if ((ppiStack120[1] != (int *)&PyDict_Type) ||
             (oparg = (int **)local_a0[5], oparg[1] != (int *)&PyDict_Type)) {
            iVar6 = *(int *)(local_6c + 0xc + (int)oparg_var14 * 4);
            piVar7 = (int *)PyObject_GetItem(ppiStack120,iVar6);
            if (piVar7 == (int *)0x0) {
              iVar11 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_KeyError);
              param_1 = local_a0;
              if (iVar11 == 0) goto LAB_101b869b;
              _PyErr_Clear(local_9c);
              piVar7 = (int *)PyObject_GetItem(local_a0[5],iVar6);
              if (piVar7 == (int *)0x0) goto LAB_101bab6c;
            }
            *ppiVar16 = piVar7;
            local_8c = ppiVar16 + 1;
            ppiVar13 = local_8c;
            piVar7 = local_a0;
            goto LAB_101b8915;
          }
          opcode = (int **)0x0;
          if ((((*(int *)(local_74 + 0x5c) != 0) &&
               (bVar3 = *(byte *)(((int)((int)puVar12 - (int)local_7c) >> 1) +
                                 *(int *)(local_74 + 0x58)), bVar3 != 0)) &&
              (opcode = (int **)(*(int *)(local_74 + 0x5c) + -0x20 + (uint)bVar3 * 0x20),
              opcode != (int **)0x0)) &&
             ((('\0' < *(char *)(opcode + 6) && (opcode[2] == ppiStack120[4])) &&
              ((opcode[3] == ppiStack120[5] &&
               ((opcode[4] == oparg[4] && (opcode[5] == oparg[5])))))))) {
            piVar15 = *opcode;
            *piVar15 = *piVar15 + 1;
            *ppiVar16 = piVar15;
            local_8c = ppiVar16 + 1;
            ppiVar13 = local_8c;
            goto LAB_101b8915;
          }
          ppiStack136 = *(int ***)(local_6c + 0xc + (int)oparg_var14 * 4);
          if ((((((ppiStack136[1] != (int *)&PyUnicode_Type) ||
                 (ppiStack128 = (int **)ppiStack136[3], ppiStack128 == (int **)0xffffffff)) &&
                (ppiStack128 = (int **)PyObject_Hash(ppiStack136), ppiStack128 == (int **)0xffffffff
                )) || (iVar6 = (*(code *)ppiStack120[6][2])
                                         (ppiStack120,ppiStack136,ppiStack128,&ppiStack88),
                      iVar6 == -3)) ||
              (((iVar6 == -1 || (ppiStack120 = ppiStack88, ppiStack88 == (int **)0x0)) &&
               (iVar6 = (*(code *)oparg[6][2])
                                  (oparg,ppiStack136,ppiStack128,&ppiStack88), iVar6 < 0))))
             || (ppiStack120 = ppiStack88, ppiStack88 == (int **)0x0)) {
            puVar20 = PyExc_NameError;
            param_1 = local_a0;
            if ((DAT_103b673c[0xd] == (int *)0x0) &&
               (iVar6 = PyUnicode_AsUTF8AndSize(ppiStack136,0), param_1 = local_a0, iVar6 != 0)) {
              _PyErr_Format(local_9c,puVar20,"name \'%.200s\' is not defined",iVar6);
              param_1 = local_a0;
            }
            goto LAB_101b869b;
          }
          if (opcode != (int **)0x0) {
            *(undefined *)(opcode + 6) = 1;
            iVar6 = local_a0[6];
            opcode[2] = *(int **)(iVar6 + 0x10);
            opcode[3] = *(int **)(iVar6 + 0x14);
            iVar6 = local_a0[5];
            opcode[4] = *(int **)(iVar6 + 0x10);
            opcode[5] = *(int **)(iVar6 + 0x14);
            *(int ***)opcode = ppiStack88;
          }
          *ppiStack88 = (int *)((int)*ppiStack88 + 1);
          *(int ***)ppiVar16 = ppiStack88;
          local_8c = ppiVar16 + 1;
          ppiVar13 = local_8c;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x7a:
          PyFrame_BlockSetup(local_a0,0x7a,
                             (int **)((int)oparg_var14 + ((int)((int)puVar12 - (int)local_7c) >> 1) * 2
                                     ),(int)((int)ppiVar16 - local_a0[8]) >> 2);
          goto LAB_101b8915;
        case (int **)0x7c:
          piVar7 = (int *)local_54[(int)oparg_var14];
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar7 + 1;
            *ppiVar16 = piVar7;
            ppiVar13 = ppiVar16 + 1;
            local_8c = ppiVar16 + 1;
            goto LAB_101b8a90;
          }
          iVar6 = PyTuple_GetItem(*(undefined4 *)(local_74 + 0x30),oparg_var14);
          puVar20 = PyExc_UnboundLocalError;
          param_1 = local_a0;
          if ((iVar6 != 0) &&
             (iVar6 = PyUnicode_AsUTF8AndSize(iVar6,0), param_1 = local_a0, iVar6 != 0)) {
            _PyErr_Format(local_9c,puVar20,"local variable \'%.200s\' referenced before assignment",
                          iVar6);
            param_1 = local_a0;
          }
          goto LAB_101b869b;
        case (int **)0x7d:
opcode_switch_caseD_7d:
          local_8c = ppiVar16 + -1;
          opcode = (int **)local_54[(int)oparg_var14];
          *(int **)(local_54 + (int)oparg_var14) = *local_8c;
          puVar12 = (ushort *)local_94;
          ppiVar13 = local_8c;
          if ((opcode == (int **)0x0) ||
             (*opcode = (int *)((int)*opcode + -1), *opcode != (int *)0x0)) goto LAB_101b8a90;
          piVar7 = opcode[1];
          goto LAB_101b8a80;
        case (int **)0x7e:
          opcode = (int **)local_54[(int)oparg_var14];
          if (opcode != (int **)0x0) {
            local_54[(int)oparg_var14] = 0;
            goto LAB_101ba4f4;
          }
          iVar6 = PyTuple_GetItem(*(undefined4 *)(local_74 + 0x30),oparg_var14);
          puVar20 = PyExc_UnboundLocalError;
          param_1 = local_a0;
          if ((iVar6 != 0) &&
             (iVar6 = PyUnicode_AsUTF8AndSize(iVar6,0), param_1 = local_a0, iVar6 != 0)) {
            _PyErr_Format(local_9c,puVar20,"local variable \'%.200s\' referenced before assignment",
                          iVar6);
            param_1 = local_a0;
          }
          goto LAB_101b869b;
        case (int **)0x82:
          piVar7 = (int *)0x0;
          if (oparg_var14 != (int **)0x0) {
            if (oparg_var14 != (int **)0x1) {
              if (oparg_var14 != (int **)0x2) {
                pcVar22 = "bad RAISE_VARARGS oparg";
                goto LAB_101bc43f;
              }
              piVar7 = ppiVar16[-1];
              ppiVar16 = ppiVar16 + -1;
            }
            ppiVar13 = ppiVar16 + -1;
          }
          iVar6 = FUN_101bdb50(piVar7);
          param_1 = local_a0;
          if (iVar6 == 0) goto LAB_101b869b;
          goto LAB_101b86e4;
        case (int **)0x83:
opcode_switch_caseD_83:
          ppiStack144 = ppiVar16;
          opcode = (int **)FUN_101beb10(oparg_var14,0);
          *(int ***)ppiStack144 = opcode;
          ppiVar13 = ppiStack144 + 1;
          local_8c = ppiVar13;
          goto joined_r0x101b9c73;
        case (int **)0x84:
          ppiStack144 = (int **)ppiVar16[-1];
          ppiVar13 = ppiVar16 + -2;
          ppiStack152 = (int **)*ppiVar13;
          opcode = (int **)PyFunction_NewWithQualName(ppiStack152,local_a0[6],ppiStack144);
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          *ppiStack144 = (int *)((int)*ppiStack144 + -1);
          if (*ppiStack144 == (int *)0x0) {
            (*(code *)ppiStack144[1][6])(ppiStack144);
          }
          param_1 = local_a0;
          if (opcode == (int **)0x0) goto LAB_101b869b;
          if (((uint)oparg & 8) != 0) {
            opcode[6] = ppiVar16[-3];
            ppiVar13 = ppiVar16 + -3;
          }
          ppiVar16 = ppiVar13;
          if (((uint)oparg & 4) != 0) {
            ppiVar13 = ppiVar16 + -1;
            ppiVar16 = ppiVar16 + -1;
            opcode[0xc] = *ppiVar13;
          }
          if (((uint)oparg & 2) != 0) {
            ppiVar13 = ppiVar16 + -1;
            ppiVar16 = ppiVar16 + -1;
            opcode[5] = *ppiVar13;
          }
          if (((uint)oparg & 1) != 0) {
            ppiVar13 = ppiVar16 + -1;
            ppiVar16 = ppiVar16 + -1;
            opcode[4] = *ppiVar13;
          }
          goto LAB_101bbeb0;
        case (int **)0x85:
          if (oparg_var14 == (int **)0x3) {
            piVar7 = ppiVar16[-1];
            ppiVar16 = ppiVar16 + -1;
          }
          else {
            piVar7 = (int *)0x0;
          }
          ppiStack144 = (int **)ppiVar16[-1];
          ppiVar13 = ppiVar16 + -1;
          ppiStack152 = (int **)ppiVar16[-2];
          local_8c = ppiVar13;
          ppiStack136 = (int **)PySlice_New(ppiStack152,ppiStack144,piVar7);
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          *ppiStack144 = (int *)((int)*ppiStack144 + -1);
          if (*ppiStack144 == (int *)0x0) {
            (*(code *)ppiStack144[1][6])(ppiStack144);
          }
          opcode = ppiStack136;
          ppiVar16 = ppiVar13;
          if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
            opcode = ppiStack136;
          }
          goto LAB_101b9b8e;
        case (int **)0x87:
          piVar15 = (int *)local_68[(int)oparg_var14];
          *piVar15 = *piVar15 + 1;
          *ppiVar16 = piVar15;
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar16 + 1;
          goto LAB_101b8915;
        case (int **)0x88:
          piVar15 = *(int **)(local_68[(int)oparg_var14] + 8);
          if (piVar15 != (int *)0x0) {
            *piVar15 = *piVar15 + 1;
            *ppiVar16 = piVar15;
            ppiVar13 = ppiVar16 + 1;
            local_8c = ppiVar16 + 1;
            goto LAB_101b8915;
          }
LAB_101bc39b:
          FUN_101bfbd0(oparg_var14);
          param_1 = local_a0;
          goto LAB_101b869b;
        case (int **)0x89:
          ppiVar13 = ppiVar16 + -1;
          piVar15 = *(int **)(local_68[(int)oparg_var14] + 8);
          *(int **)(local_68[(int)oparg_var14] + 8) = *ppiVar13;
          local_8c = ppiVar13;
          if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
            (**(code **)(piVar15[1] + 0x18))(piVar15);
          }
          goto LAB_101b8915;
        case (int **)0x8a:
          opcode = *(int ***)(local_68[(int)oparg_var14] + 8);
          if (opcode == (int **)0x0) goto LAB_101bc39b;
          *(undefined4 *)(local_68[(int)oparg_var14] + 8) = 0;
LAB_101ba4f4:
          *opcode = (int *)((int)*opcode + -1);
          if (*opcode == (int *)0x0) {
            (*(code *)opcode[1][6])(opcode);
          }
          goto LAB_101b8915;
        case (int **)0x8d:
          piVar7 = ppiVar16[-1];
          ppiStack152 = ppiVar16 + -1;
          ppiStack144 = (int **)FUN_101beb10(oparg_var14,piVar7);
          *(int ***)ppiStack152 = ppiStack144;
          ppiVar13 = ppiStack152 + 1;
          *piVar7 = *piVar7 + -1;
          local_8c = ppiVar13;
          opcode = ppiStack144;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
            opcode = ppiStack144;
          }
          goto joined_r0x101b9c73;
        case (int **)0x8e:
          oparg_var14 = (int **)0x0;
          if (((uint)oparg_var14 & 1) != 0) {
            opcode = (int **)ppiVar16[-1];
            ppiVar13 = ppiVar16 + -1;
            oparg_var14 = opcode;
            if (opcode[1] != (int *)&PyDict_Type) {
              _DAT_103b30f4 = _DAT_103b30f4 + 1;
              ppiStack152 = (int **)FUN_1010c4d0();
              param_1 = local_a0;
              if (ppiStack152 == (int **)0x0) goto LAB_101b869b;
              iVar6 = FUN_1010fd20(2);
              if (iVar6 < 0) {
                *ppiStack152 = (int *)((int)*ppiStack152 + -1);
                if (*ppiStack152 == (int *)0x0) {
                  (*(code *)ppiStack152[1][6])(ppiStack152);
                }
                FUN_101bf950(opcode);
                ppiVar16 = ppiVar13;
                goto LAB_101b8a45;
              }
              *opcode = (int *)((int)*opcode + -1);
              oparg_var14 = ppiStack152;
              if (*opcode == (int *)0x0) {
                (*(code *)opcode[1][6])(opcode);
                oparg_var14 = ppiStack152;
              }
            }
          }
          oparg = (int **)ppiVar13[-1];
          ppiVar16 = ppiVar13 + -1;
          ppiStack152 = (int **)ppiVar13[-2];
          local_8c = ppiVar16;
          if (oparg[1] != (int *)&PyTuple_Type) {
            iVar6 = FUN_101bf8c0(oparg);
            opcode = oparg;
            param_1 = local_a0;
            if (iVar6 < 0) goto LAB_101bc1a8;
            ppiStack144 = oparg;
            oparg = (int **)PySequence_Tuple(oparg);
            *ppiStack144 = (int *)((int)*ppiStack144 + -1);
            if (*ppiStack144 == (int *)0x0) {
              (*(code *)ppiStack144[1][6])(ppiStack144);
            }
            ppiVar13 = ppiVar16;
            param_1 = local_a0;
            if (oparg == (int **)0x0) goto LAB_101b869b;
          }
          ppiStack144 = (int **)FUN_101beba0(oparg,oparg_var14);
          *ppiStack152 = (int *)((int)*ppiStack152 + -1);
          if (*ppiStack152 == (int *)0x0) {
            (*(code *)ppiStack152[1][6])(ppiStack152);
          }
          *oparg = (int *)((int)*oparg + -1);
          if (*oparg == (int *)0x0) {
            (*(code *)oparg[1][6])(oparg);
          }
          opcode = ppiStack144;
          if (oparg_var14 == (int **)0x0) goto LAB_101b9b8e;
          goto LAB_101b9e01;
        case (int **)0x8f:
          ppiStack144 = (int **)ppiVar16[-1];
          opcode = (int **)FUN_101bdae0(&DAT_103b4f04);
          param_1 = local_a0;
          if (opcode == (int **)0x0) goto LAB_101b869b;
          piVar7 = (int *)FUN_101bdae0(&DAT_103b4ebc);
          if (piVar7 == (int *)0x0) goto LAB_101b8a45;
          ppiVar16[-1] = piVar7;
          *ppiStack144 = (int *)((int)*ppiStack144 + -1);
          if (*ppiStack144 == (int *)0x0) {
            (*(code *)ppiStack144[1][6])(ppiStack144);
          }
          ppiStack144 = (int **)FUN_101b70d0(0,0);
          *opcode = (int *)((int)*opcode + -1);
          if (*opcode == (int *)0x0) {
            (*(code *)opcode[1][6])(opcode);
          }
          piVar7 = local_a0;
          param_1 = local_a0;
          if (ppiStack144 == (int **)0x0) goto LAB_101b869b;
          PyFrame_BlockSetup(local_a0,0x7a,
                             (int **)((int)oparg +
                                     ((int)((int)local_94 - (int)local_7c) >> 1) * 2),
                             (int)((int)ppiVar16 - local_a0[8]) >> 2);
          *(int ***)ppiVar16 = ppiStack144;
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar16 + 1;
          goto LAB_101b8915;
        case (int **)0x90:
          goto opcode_switch_caseD_90;
        case (int **)0x91:
          piVar7 = ppiVar16[-1];
          ppiVar13 = ppiVar16 + -1;
          local_8c = ppiVar13;
          if (((*(uint *)(ppiVar13[(int)oparg_var14 * 0x3fffffff][1] + 0x54) & 0x2000000) == 0) ||
             (piVar7 == (int *)0x0)) {
            _PyErr_Format(DAT_103b673c,PyExc_SystemError,"%s:%d: bad argument to internal function",
                          "D:\\a\\1\\s\\Objects\\listobject.c",0x161);
            ppiStack136 = (int **)0xffffffff;
          }
          else {
            ppiStack136 = (int **)FUN_10126cf0();
          }
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          bVar18 = ppiStack136 == (int **)0x0;
          goto LAB_101ba0dd;
        case (int **)0x92:
          piVar7 = ppiVar16[-1];
          ppiVar13 = ppiVar16 + -1;
          local_8c = ppiVar13;
          ppiStack152 = (int **)PySet_Add(ppiVar13[(int)oparg_var14 * 0x3fffffff],piVar7);
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          bVar18 = ppiStack152 == (int **)0x0;
          goto LAB_101ba0dd;
        case (int **)0x93:
          ppiStack144 = (int **)ppiVar16[-1];
          ppiVar13 = ppiVar16 + -2;
          piVar7 = *ppiVar13;
          local_8c = ppiVar13;
          ppiStack152 = (int **)PyDict_SetItem(ppiVar13[(int)oparg_var14 * 0x3fffffff],piVar7,
                                               ppiStack144);
          *ppiStack144 = (int *)((int)*ppiStack144 + -1);
          if (*ppiStack144 == (int *)0x0) {
            (*(code *)ppiStack144[1][6])(ppiStack144);
          }
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (**(code **)(piVar7[1] + 0x18))(piVar7);
          }
          bVar18 = ppiStack152 == (int **)0x0;
LAB_101ba0dd:
          param_1 = local_a0;
          if (!bVar18) goto LAB_101b869b;
          piVar7 = local_a0;
          if ((char)*(ushort *)local_94 == 'q') {
            oparg_var14 = (int **)(uint)(*(ushort *)local_94 >> 8);
opcode_switch_caseD_71:
            piVar7 = local_a0;
            local_94 = (int *)((int)local_7c + ((uint)oparg_var14 & 0xfffffffe));
          }
          goto LAB_101b8915;
        case (int **)0x94:
          if (*(undefined **)(local_a0[7] + 4) == &PyDict_Type) {
            piVar7 = (int *)PyDict_GetItemWithError();
            if (piVar7 == (int *)0x0) {
              param_1 = local_a0;
              if (local_9c[0xd] != (int *)0x0) goto LAB_101b869b;
LAB_101baf94:
              piVar7 = *(int **)(local_68[(int)oparg] + 8);
              if (piVar7 == (int *)0x0) {
                FUN_101bfbd0(oparg);
                param_1 = local_a0;
                goto LAB_101b869b;
              }
            }
            *piVar7 = *piVar7 + 1;
          }
          else {
            piVar7 = (int *)PyObject_GetItem(local_a0[7],
                                             *(undefined4 *)
                                              (*(int *)(local_74 + 0x34) + 0xc +
                                              (int)((int)oparg_var14 -
                                                   *(int *)(*(int *)(local_74 + 0x38) + 8)) * 4));
            if (piVar7 == (int *)0x0) {
              iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_KeyError);
              param_1 = local_a0;
              if (iVar6 != 0) {
                _PyErr_Clear(local_9c);
                goto LAB_101baf94;
              }
              goto LAB_101b869b;
            }
          }
          *ppiVar16 = piVar7;
          local_8c = ppiVar16 + 1;
          ppiVar13 = local_8c;
          piVar7 = local_a0;
          goto LAB_101b8915;
        case (int **)0x95:
        case (int **)0x98:
        case (int **)0x9e:
          ppiStack128 = (int **)PyList_New(0);
          param_1 = local_a0;
          if (ppiStack128 == (int **)0x0) goto LAB_101b869b;
          ppiStack120 = oparg;
          if ((int)oparg < 1) goto LAB_101bb1b4;
          local_8c = ppiVar16 + (int)oparg * 0x3fffffff;
          goto LAB_101bb172;
        case (int **)0x96:
          _DAT_103b30f4 = _DAT_103b30f4 + 1;
          ppiStack136 = (int **)FUN_1010c4d0();
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          ppiStack144 = oparg;
          if ((int)oparg < 1) goto LAB_101bb6fb;
          opcode = ppiVar16 + (int)oparg * 0x3fffffff;
          goto LAB_101bb6c3;
        case (int **)0x97:
          _DAT_103b30f4 = _DAT_103b30f4 + 1;
          ppiStack136 = (int **)FUN_1010c4d0();
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          ppiStack144 = oparg;
          if ((int)oparg < 1) goto LAB_101bb7a8;
          opcode = ppiVar16 + (int)oparg * 0x3fffffff;
          goto LAB_101bb770;
        case (int **)0x99:
          ppiStack136 = (int **)PySet_New(0);
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          ppiStack144 = oparg;
          if ((int)oparg < 1) goto joined_r0x101bb381;
          ppiVar13 = ppiVar16 + (int)oparg * 0x3fffffff;
          goto LAB_101bb354;
        case (int **)0x9a:
          ppiStack152 = (int **)ppiVar16[-1];
          PyFrame_BlockSetup(local_a0,0x7a,
                             (int **)((int)oparg_var14 + ((int)((int)puVar12 - (int)local_7c) >> 1) * 2
                                     ),(int)ppiVar16 + (-4 - local_a0[8]) >> 2);
          *(int ***)(ppiVar16 + -1) = ppiStack152;
          ppiVar13 = ppiStack144;
          piVar7 = local_a0;
          local_8c = ppiStack144;
          goto LAB_101b8915;
        case (int **)0x9b:
          if (((uint)oparg_var14 & 4) == 0) {
            oparg = (int **)0x0;
          }
          else {
            oparg = (int **)ppiVar16[-1];
            ppiVar16 = ppiVar16 + -1;
          }
          oparg_var14 = (int **)ppiVar16[-1];
          ppiVar13 = ppiVar16 + -1;
          ppiStack144 = ppiVar16;
          switch((uint)oparg_var14 & 3) {
          case 1:
            pcVar9 = PyObject_Str;
            break;
          case 2:
            pcVar9 = PyObject_Repr;
            break;
          case 3:
            pcVar9 = PyObject_ASCII;
            break;
          case 0:
            goto opcode_switch_caseD_0;
          }
          ppiStack152 = (int **)(*pcVar9)(oparg_var14);
          *oparg_var14 = (int *)((int)*oparg_var14 + -1);
          if (*oparg_var14 == (int *)0x0) {
            (*(code *)oparg_var14[1][6])(oparg_var14);
          }
          oparg_var14 = ppiStack152;
          ppiVar16 = ppiVar13;
          param_1 = local_a0;
          opcode = oparg;
          if (ppiStack152 == (int **)0x0) goto joined_r0x101bc219;
opcode_switch_caseD_0:
          if ((oparg_var14[1] == (int *)&PyUnicode_Type) && (oparg == (int **)0x0)) {
            *(int ***)ppiVar13 = oparg_var14;
            ppiVar13 = ppiStack144;
            piVar7 = local_a0;
            local_8c = ppiStack144;
            goto LAB_101b8915;
          }
          ppiStack152 = (int **)PyObject_Format(oparg_var14,oparg);
          *oparg_var14 = (int *)((int)*oparg_var14 + -1);
          if (*oparg_var14 == (int *)0x0) {
            (*(code *)oparg_var14[1][6])(oparg_var14);
          }
          if ((oparg != (int **)0x0) &&
             (*oparg = (int *)((int)*oparg + -1), *oparg == (int *)0x0)) {
            (*(code *)oparg[1][6])(oparg);
          }
          param_1 = local_a0;
          if (ppiStack152 == (int **)0x0) goto LAB_101b869b;
          *(int ***)ppiVar13 = ppiStack152;
          ppiVar13 = ppiStack144;
          piVar7 = local_a0;
          local_8c = ppiStack144;
          goto LAB_101b8915;
        case (int **)0x9c:
          ppiStack128 = ppiVar16 + -1;
          ppiStack152 = (int **)*ppiStack128;
          if ((ppiStack152[1] != (int *)&PyTuple_Type) || ((int **)ppiStack152[2] != oparg_var14)) {
            pcVar22 = "bad BUILD_CONST_KEY_MAP keys argument";
LAB_101bc43f:
            _PyErr_SetString(local_9c,PyExc_SystemError,pcVar22);
            param_1 = local_a0;
            goto LAB_101b869b;
          }
          ppiStack136 = (int **)_PyDict_NewPresized(oparg_var14);
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          ppiStack144 = oparg;
          if ((int)oparg < 1) goto LAB_101bb634;
          ppiVar13 = (int **)((int)ppiVar16 - ((int)oparg * 4 + 4));
          ppiStack120 = ppiStack152 + 3;
          goto LAB_101bb600;
        case (int **)0x9d:
          opcode = (int **)PyUnicode_New(0,0);
          param_1 = local_a0;
          ppiStack152 = opcode;
          if (opcode == (int **)0x0) goto LAB_101b869b;
          ppiStack136 = (int **)_PyUnicode_JoinArray
                                          (opcode,ppiVar16 + (int)oparg * 0x3fffffff,
                                           oparg);
          *opcode = (int *)((int)*opcode + -1);
          if (*opcode == (int *)0x0) {
            (*(code *)opcode[1][6])(opcode);
          }
          piVar7 = local_a0;
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          while (oparg = (int **)((int)oparg + -1), -1 < (int)oparg) {
            piVar15 = ppiVar16[-1];
            ppiVar16 = ppiVar16 + -1;
            *piVar15 = *piVar15 + -1;
            if (*piVar15 == 0) {
              (**(code **)(piVar15[1] + 0x18))(piVar15);
            }
          }
          *(int ***)ppiVar16 = ppiStack136;
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar16 + 1;
          goto LAB_101b8915;
        case (int **)0xa0:
          piVar7 = ppiVar16[-1];
          ppiStack136 = (int **)0x0;
          iVar6 = FUN_1013e1a0(&ppiStack136);
          param_1 = local_a0;
          if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
          if (iVar6 == 0) {
            ppiVar16[-1] = (int *)0x0;
            *piVar7 = *piVar7 + -1;
            opcode = ppiStack136;
            if (*piVar7 == 0) {
              (**(code **)(piVar7[1] + 0x18))(piVar7);
              opcode = ppiStack136;
            }
LAB_101bbc5b:
            *(int ***)ppiVar16 = opcode;
            ppiVar13 = ppiVar16 + 1;
            piVar7 = local_a0;
            local_8c = ppiVar16 + 1;
          }
          else {
            *(int ***)(ppiVar16 + -1) = ppiStack136;
            *ppiVar16 = piVar7;
            ppiVar13 = ppiVar16 + 1;
            piVar7 = local_a0;
            local_8c = ppiVar16 + 1;
          }
          goto LAB_101b8915;
        case (int **)0xa1:
          ppiStack128 = ppiVar16;
          if (*(int **)((int)ppiVar16 - ((int)oparg_var14 * 4 + 8)) == (int *)0x0) {
            opcode = (int **)FUN_101beb10(oparg_var14,0);
            *(int ***)(ppiStack128 + -1) = opcode;
            ppiVar13 = ppiStack128;
            local_8c = ppiStack128;
          }
          else {
            opcode = (int **)FUN_101beb10((int)oparg_var14 + 1,0);
            *(int ***)ppiStack128 = opcode;
            ppiVar13 = ppiStack128 + 1;
            local_8c = ppiStack128 + 1;
          }
          goto joined_r0x101b9c73;
        case (int **)0xa2:
          piVar7 = (int *)PyLong_FromLong((uint)((int)puVar12 - (int)local_7c) & 0xfffffffe);
          param_1 = local_a0;
          if (piVar7 == (int *)0x0) goto LAB_101b869b;
          *ppiVar16 = piVar7;
          puVar12 = (ushort *)((int)local_94 + ((uint)oparg & 0xfffffffe));
          ppiVar13 = ppiVar16 + 1;
          local_8c = ppiVar16 + 1;
          goto LAB_101b8a90;
        case (int **)0xa3:
          goto opcode_switch_caseD_a3;
                   
        ppiVar16 = ppiVar16 + -1;
        *ppiStack152 = (int *)((int)*ppiStack152 + -1);
        if (*ppiStack152 == (int *)0x0) {
          (*(code *)ppiStack152[1][6])(ppiStack152);
        }
LAB_101b9e01:
        *oparg_var14 = (int *)((int)*oparg_var14 + -1);
        opcode = ppiStack144;
        if (*oparg_var14 == (int *)0x0) {
          (*(code *)oparg_var14[1][6])(oparg_var14);
          opcode = ppiStack144;
        }
LAB_101b9b8e:
        *(int ***)(ppiVar16 + -1) = opcode;
        ppiVar13 = ppiVar16;
joined_r0x101b9c73:
        param_1 = local_a0;
        piVar7 = local_a0;
        if (opcode == (int **)0x0) goto LAB_101b869b;
        goto LAB_101b8915;
      }
    }
  } while( true );
opcode_switch_caseD_a3:
  ppiStack120 = (int **)0x0;
  if (oparg_var14 != (int **)0x0) {
    ppiStack120 = (int **)ppiVar16[-1];
    ppiVar16 = ppiVar16 + -1;
  }
  opcode = (int **)ppiVar16[-1];
  oparg_var14 = ppiVar16 + -1;
  local_8c = oparg_var14;
  if (opcode != (int **)0x0) {
    piVar7 = (int *)((int)*opcode + -1);
    *opcode = piVar7;
    if (opcode[1] == (int *)&PyLong_Type) {
      pcVar9 = pcRam103a4140;
      if (piVar7 == (int *)0x0) {
LAB_101ba7fe:
        (*pcVar9)(opcode);
      }
      goto LAB_101ba80b;
    }
    if (piVar7 == (int *)0x0) {
      (*(code *)opcode[1][6])(opcode);
    }
    piVar7 = ppiVar16[-2];
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      (**(code **)(piVar7[1] + 0x18))(piVar7);
    }
    piVar7 = ppiVar16[-3];
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      (**(code **)(piVar7[1] + 0x18))(piVar7);
    }
    param_1 = local_a0;
    if (local_a0[0xf] < 1) goto LAB_101bc7e2;
    iVar6 = local_a0[0xf] + -1;
    local_a0[0xf] = iVar6;
    if (local_a0[iVar6 * 3 + 0x11] == 0x101) {
      opcode = (int **)local_9c[0x14];
      ppiStack152 = (int **)opcode[2];
      piVar7 = *opcode;
      piVar15 = opcode[1];
      *opcode = ppiVar16[-4];
      oparg_var14 = ppiVar16 + -6;
      opcode[1] = ppiVar16[-5];
      opcode[2] = *oparg_var14;
      local_8c = oparg_var14;
      if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
        (**(code **)(piVar15[1] + 0x18))(piVar15);
      }
      if ((ppiStack152 != (int **)0x0) &&
         (*ppiStack152 = (int *)((int)*ppiStack152 + -1), *ppiStack152 == (int *)0x0)) {
        pcVar9 = (code *)ppiStack152[1][6];
        opcode = ppiStack152;
        goto LAB_101ba7fe;
      }
      goto LAB_101ba80b;
    }
    _PyErr_SetString(local_9c,PyExc_SystemError,"popped block is not an except handler");
    ppiVar16 = ppiVar16 + -3;
    opcode = ppiStack120;
joined_r0x101bc219:
    ppiVar13 = ppiVar16;
    if (opcode == (int **)0x0) goto LAB_101b869b;
    goto LAB_101bc1a8;
  }
LAB_101ba80b:
  ppiVar13 = oparg_var14;
  piVar7 = local_a0;
  if (oparg != (int **)0x0) {
    *(int ***)oparg_var14 = ppiStack120;
    ppiVar13 = oparg_var14 + 1;
    local_8c = oparg_var14 + 1;
  }
  goto LAB_101b8915;
  while( true ) {
    ppiVar13 = ppiVar13 + 1;
    ppiStack144 = (int **)((int)ppiStack144 + -1);
    ppiStack120 = ppiStack120 + 1;
    if ((int)ppiStack144 < 1) break;
LAB_101bb600:
    iVar6 = PyDict_SetItem(ppiStack136,*ppiStack120,*ppiVar13);
    opcode = ppiStack136;
    param_1 = local_a0;
    if (iVar6 != 0) goto LAB_101bc1a8;
  }
LAB_101bb634:
  ppiVar16 = ppiStack128;
  piVar7 = *ppiStack128;
  *piVar7 = *piVar7 + -1;
  if (*piVar7 == 0) {
    (**(code **)(piVar7[1] + 0x18))(piVar7);
  }
  if (oparg != (int **)0x0) {
    do {
      ppiVar13 = ppiVar16;
      piVar7 = ppiVar13[-1];
      oparg = (int **)((int)oparg + -1);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      ppiVar16 = ppiVar13 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar13 + -1) = ppiStack136;
    piVar7 = local_a0;
    local_8c = ppiVar13;
    goto LAB_101b8915;
  }
LAB_101bb3a7:
  *(int ***)ppiVar16 = ppiStack136;
  ppiVar13 = ppiVar16 + 1;
  piVar7 = local_a0;
  local_8c = ppiVar16 + 1;
  goto LAB_101b8915;
  while( true ) {
    ppiVar13 = ppiVar13 + 1;
    ppiStack144 = (int **)((int)ppiStack144 + -1);
    if ((int)ppiStack144 < 1) break;
LAB_101bb354:
    iVar6 = _PySet_Update(ppiStack136,*ppiVar13);
    opcode = ppiStack136;
    param_1 = local_a0;
    if (iVar6 < 0) goto LAB_101bc1a8;
  }
joined_r0x101bb381:
  while (oparg != (int **)0x0) {
    piVar7 = ppiVar16[-1];
    ppiVar16 = ppiVar16 + -1;
    oparg = (int **)((int)oparg + -1);
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      (**(code **)(piVar7[1] + 0x18))(piVar7);
    }
  }
  goto LAB_101bb3a7;
  while( true ) {
    opcode = opcode + 1;
    ppiStack144 = (int **)((int)ppiStack144 + -1);
    if ((int)ppiStack144 < 1) break;
LAB_101bb770:
    ppiStack152 = (int **)*opcode;
    iVar6 = FUN_1010fd20(2);
    if (iVar6 < 0) {
      *ppiStack136 = (int *)((int)*ppiStack136 + -1);
      if (*ppiStack136 == (int *)0x0) {
        (*(code *)ppiStack136[1][6])(ppiStack136);
      }
      FUN_101bf950(ppiStack152);
      param_1 = local_a0;
      goto LAB_101b869b;
    }
  }
LAB_101bb7a8:
  opcode = ppiStack136;
  if (oparg != (int **)0x0) {
    do {
      ppiVar13 = ppiVar16;
      piVar7 = ppiVar13[-1];
      oparg = (int **)((int)oparg + -1);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      ppiVar16 = ppiVar13 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar13 + -1) = opcode;
    piVar7 = local_a0;
    local_8c = ppiVar13;
    goto LAB_101b8915;
  }
LAB_101bbeb0:
  *(int ***)ppiVar16 = opcode;
  ppiVar13 = ppiVar16 + 1;
  piVar7 = local_a0;
  local_8c = ppiVar16 + 1;
  goto LAB_101b8915;
  while( true ) {
    opcode = opcode + 1;
    ppiStack144 = (int **)((int)ppiStack144 + -1);
    if ((int)ppiStack144 < 1) break;
LAB_101bb6c3:
    ppiStack152 = (int **)*opcode;
    iVar6 = FUN_1010fd20(1);
    ppiVar13 = local_9c;
    if (iVar6 < 0) {
      iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_AttributeError);
      opcode = ppiStack136;
      param_1 = local_a0;
      if (iVar6 != 0) {
        _PyErr_Format(ppiVar13,PyExc_TypeError,"\'%.200s\' object is not a mapping",
                      ppiStack152[1][3]);
        opcode = ppiStack136;
        param_1 = local_a0;
      }
      goto LAB_101bc1a8;
    }
  }
LAB_101bb6fb:
  opcode = ppiStack136;
  if (oparg != (int **)0x0) {
    do {
      ppiVar13 = ppiVar16;
      piVar7 = ppiVar13[-1];
      oparg = (int **)((int)oparg + -1);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      ppiVar16 = ppiVar13 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar13 + -1) = opcode;
    piVar7 = local_a0;
    local_8c = ppiVar13;
    goto LAB_101b8915;
  }
  goto LAB_101bbeb0;
  while( true ) {
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      (**(code **)(piVar7[1] + 0x18))(piVar7);
    }
    ppiStack120 = (int **)((int)ppiStack120 + -1);
    local_8c = local_8c + 1;
    if ((int)ppiStack120 < 1) break;
LAB_101bb172:
    piVar7 = (int *)FUN_10127b70(ppiStack128,*local_8c);
    if (piVar7 == (int *)0x0) {
      opcode = ppiStack128;
      if ((ppiStack136 == (int **)0x9e) &&
         (iVar6 = PyErr_GivenExceptionMatches(local_9c[0xd],PyExc_TypeError), opcode = ppiStack128,
         iVar6 != 0)) {
        FUN_101bf8c0(ppiVar16[(int)ppiStack120 * 0x3fffffff]);
        opcode = ppiStack128;
      }
      goto LAB_101b8a45;
    }
  }
LAB_101bb1b4:
  opcode = ppiStack128;
  if (ppiStack136 != (int **)0x95) {
    if ((ppiStack128[1][0x15] & 0x2000000U) == 0) {
      _PyErr_Format(DAT_103b673c,PyExc_SystemError,"%s:%d: bad argument to internal function",
                    "D:\\a\\1\\s\\Objects\\listobject.c",0x9dd);
      ppiStack136 = (int **)0x0;
      opcode = ppiStack128;
    }
    else {
      ppiStack136 = (int **)FUN_1014ee00();
    }
    *opcode = (int *)((int)*opcode + -1);
    if (*opcode == (int *)0x0) {
      (*(code *)opcode[1][6])(opcode);
    }
    param_1 = local_a0;
    opcode = ppiStack136;
    if (ppiStack136 == (int **)0x0) goto LAB_101b869b;
  }
  if (oparg != (int **)0x0) {
    do {
      ppiVar13 = ppiVar16;
      piVar7 = ppiVar13[-1];
      oparg = (int **)((int)oparg + -1);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      ppiVar16 = ppiVar13 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar13 + -1) = opcode;
    piVar7 = local_a0;
    local_8c = ppiVar13;
    goto LAB_101b8915;
  }
  goto LAB_101bbeb0;
opcode_switch_caseD_90:
  uVar5 = *puVar12;
  oparg_var14 = (int **)((int)oparg_var14 << 8 | (uint)(uVar5 >> 8));
  goto LAB_101b8c40;
  while( true ) {
    iVar6 = iVar6 + 1;
    opcode = opcode + 1;
    if ((int)ppiStack152 <= iVar6) break;
LAB_101b90d1:
    if ((-1 < *(int *)((*opcode)[1] + 0x54)) || (((*opcode)[0x15] & 0x40000000U) == 0))
    goto LAB_101b9113;
  }
LAB_101b90f7:
  uVar17 = PyErr_GivenExceptionMatches(ppiStack128,oparg);
LAB_101b9103:
  piVar7 = &_Py_TrueStruct;
  if (uVar17 == 0) {
    piVar7 = &_Py_FalseStruct;
  }
  *piVar7 = *piVar7 + 1;
LAB_101b914a:
  *ppiStack128 = (int *)((int)*ppiStack128 + -1);
  if (*ppiStack128 == (int *)0x0) {
    (*(code *)ppiStack128[1][6])(ppiStack128);
  }
  *oparg = (int *)((int)*oparg + -1);
  if (*oparg == (int *)0x0) {
    (*(code *)oparg[1][6])(oparg);
  }
  ppiVar16[-2] = piVar7;
  param_1 = local_a0;
  if (piVar7 == (int *)0x0) goto LAB_101b869b;
  uVar5 = *(ushort *)local_94;
  if ((uVar5 & 0xff) == 0x72) {
    oparg = (int **)(uint)(uVar5 >> 8);
    puVar12 = (ushort *)local_94 + 1;
opcode_switch_caseD_72:
    opcode = (int **)ppiVar13[-1];
    ppiVar13 = ppiVar13 + -1;
    local_94 = (int *)puVar12;
    local_8c = ppiVar13;
    if (opcode != (int **)&_Py_TrueStruct) {
      if (opcode != (int **)&_Py_FalseStruct) {
        ppiStack152 = (int **)PyObject_IsTrue(opcode);
        *opcode = (int *)((int)*opcode + -1);
        if (*opcode == (int *)0x0) {
          (*(code *)opcode[1][6])(opcode);
        }
        piVar7 = local_a0;
        if (0 < (int)ppiStack152) goto LAB_101b8915;
        param_1 = local_a0;
        if (ppiStack152 != (int **)0x0) goto LAB_101b869b;
        local_94 = (int *)((int)local_7c + ((uint)oparg & 0xfffffffe));
        goto LAB_101b8915;
      }
LAB_101b9257:
      *opcode = (int *)((int)*opcode + -1);
      local_8c = ppiVar13;
      if (*opcode == (int *)0x0) {
        (*(code *)opcode[1][6])(opcode);
      }
      puVar12 = (ushort *)((int)local_7c + ((uint)oparg & 0xfffffffe));
      goto LAB_101b8a90;
    }
  }
  else {
    piVar7 = local_a0;
    if ((uVar5 & 0xff) != 0x73) goto LAB_101b8915;
    oparg = (int **)(uint)(uVar5 >> 8);
    puVar12 = (ushort *)local_94 + 1;
opcode_switch_caseD_73:
    opcode = (int **)ppiVar13[-1];
    ppiVar13 = ppiVar13 + -1;
    local_94 = (int *)puVar12;
    local_8c = ppiVar13;
    if (opcode != (int **)&_Py_FalseStruct) {
      if (opcode != (int **)&_Py_TrueStruct) {
        ppiStack152 = (int **)PyObject_IsTrue(opcode);
        *opcode = (int *)((int)*opcode + -1);
        if (*opcode == (int *)0x0) {
          (*(code *)opcode[1][6])(opcode);
        }
        opcode = ppiStack152;
        if (0 < (int)ppiStack152) {
          piVar7 = local_a0;
          local_94 = (int *)((int)local_7c + ((uint)oparg & 0xfffffffe));
          goto LAB_101b8915;
        }
joined_r0x101baa38:
        param_1 = local_a0;
        piVar7 = local_a0;
        if (opcode != (int **)0x0) goto LAB_101b869b;
        goto LAB_101b8915;
      }
      goto LAB_101b9257;
    }
  }
LAB_101b8a73:
  *opcode = (int *)((int)*opcode + -1);
  puVar12 = (ushort *)local_94;
  ppiVar13 = local_8c;
  if (*opcode != (int *)0x0) goto LAB_101b8a90;
  piVar7 = opcode[1];
LAB_101b8a80:
  ppiVar13 = local_8c;
  (*(code *)piVar7[6])(opcode);
  puVar12 = (ushort *)local_94;
  goto LAB_101b8a90;
LAB_101b9113:
  _PyErr_SetString(local_9c,PyExc_TypeError,
                   "catching classes that do not inherit from BaseException is not allowed");
  piVar7 = (int *)0x0;
  goto LAB_101b914a;
switchD_101b9016_caseD_7:
  if ((oparg[1][0xd] == 0) ||
     (pcVar9 = *(code **)(oparg[1][0xd] + 0x1c), pcVar9 == (code *)0x0)) {
    iVar6 = _PySequence_IterSearch(oparg,ppiStack128,3);
  }
  else {
    iVar6 = (*pcVar9)(oparg,ppiStack128);
  }
  if (-1 < iVar6) {
    uVar17 = (uint)(iVar6 == 0);
    goto LAB_101b9103;
  }
  piVar7 = (int *)0x0;
  goto LAB_101b914a;
  while( true ) {
    ppiVar13 = ppiVar13 + 2;
    ppiStack144 = (int **)((int)ppiStack144 + -1);
    if ((int)ppiStack144 < 1) break;
LAB_101bb3e7:
    iVar6 = PyDict_SetItem(ppiStack136,*ppiVar13,ppiVar13[1]);
    opcode = ppiStack136;
    param_1 = local_a0;
    if (iVar6 != 0) goto LAB_101bc1a8;
  }
LAB_101bb417:
  if (oparg != (int **)0x0) {
    do {
      opcode = ppiVar16;
      piVar7 = opcode[-1];
      oparg = (int **)((int)oparg + -1);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      piVar7 = opcode[-2];
      *piVar7 = *piVar7 + -1;
      if (*piVar7 == 0) {
        (**(code **)(piVar7[1] + 0x18))(piVar7);
      }
      ppiVar16 = opcode + -2;
    } while (oparg != (int **)0x0);
    *(int ***)(opcode + -2) = ppiStack136;
    local_8c = opcode + -1;
    ppiVar13 = local_8c;
    piVar7 = local_a0;
    goto LAB_101b8915;
  }
  goto LAB_101bb3a7;
joined_r0x101b9a12:
  while (ppiVar4 = ppiVar16, oparg_var14 != (int **)0x0) {
    piVar7 = ppiStack136[(int)oparg_var14 + 2];
    oparg_var14 = (int **)((int)oparg_var14 + -1);
    *piVar7 = *piVar7 + 1;
    *ppiVar16 = piVar7;
    ppiVar16 = ppiVar16 + 1;
  }
LAB_101bbaab:
  local_8c = ppiVar4;
  ppiVar13 = local_8c;
  *opcode = (int *)((int)*opcode + -1);
  piVar7 = local_a0;
  if (*opcode == (int *)0x0) {
    (*(code *)opcode[1][6])(opcode);
    piVar7 = local_a0;
  }
  goto LAB_101b8915;
LAB_101b8e53:
  iVar6 = PyErr_GivenExceptionMatches(ppiStack136,*ppiVar13);
  opcode = ppiStack136;
  if (iVar6 != 0) goto LAB_101b8ee3;
  ppiVar13 = ppiVar13 + 1;
  ppiStack120 = (int **)((int)ppiStack120 + 1);
  if ((int)ppiStack144 <= (int)ppiStack120) goto LAB_101b8e7b;
  goto LAB_101b8e53;
LAB_101b8ee3:
  if (local_a0[0xf] < 1) {
LAB_101bc7e2:
                    /* WARNING: Subroutine does not return */
    Py_FatalError("XXX block stack underflow");
  }
  iVar6 = local_a0[0xf] + -1;
  local_a0[0xf] = iVar6;
  *opcode = (int *)((int)*opcode + -1);
  ppiStack152 = (int **)(local_a0 + iVar6 * 3);
  if (*opcode == (int *)0x0) {
    (*(code *)opcode[1][6])(opcode);
  }
  piVar7 = (int *)ppiStack152;
  if (((int *)ppiStack152)[0x13] + 3 < (int)((int)ppiVar16 - local_a0[8]) >> 2) {
    do {
      piVar15 = ppiVar16[-1];
      ppiVar16 = ppiVar16 + -1;
      if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
        (**(code **)(piVar15[1] + 0x18))(piVar15);
      }
    } while (piVar7[0x13] + 3 < (int)((int)ppiVar16 - local_a0[8]) >> 2);
  }
  opcode = (int **)local_9c[0x14];
  ppiStack152 = (int **)opcode[2];
  piVar7 = *opcode;
  piVar15 = opcode[1];
  *opcode = ppiVar16[-1];
  opcode[1] = ppiVar16[-2];
  opcode[2] = ppiVar16[-3];
  if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
    (**(code **)(piVar7[1] + 0x18))(piVar7);
  }
  if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
    (**(code **)(piVar15[1] + 0x18))(piVar15);
  }
  if ((ppiStack152 != (int **)0x0) &&
     (*ppiStack152 = (int *)((int)*ppiStack152 + -1), *ppiStack152 == (int *)0x0)) {
    (*(code *)ppiStack152[1][6])(ppiStack152);
  }
  piVar7 = ppiVar16[-4];
  ppiVar13 = ppiVar16 + -4;
  *piVar7 = *piVar7 + -1;
  local_8c = ppiVar13;
  if (*piVar7 == 0) {
    (**(code **)(piVar7[1] + 0x18))(piVar7);
  }
  puVar12 = (ushort *)((int)local_94 + ((uint)oparg & 0xfffffffe));
  goto LAB_101b8a90;
LAB_101b8e7b:
  ppiVar13 = ppiVar16 + -2;
  _PyErr_Restore(local_9c,opcode,ppiVar16[-1],*ppiVar13);
  param_1 = local_a0;
  goto LAB_101b86e4;
LAB_101bc1a8:
  *opcode = (int *)((int)*opcode + -1);
  ppiVar13 = ppiVar16;
  if (*opcode == (int *)0x0) {
    (*(code *)opcode[1][6])(opcode);
  }
  goto LAB_101b869b;
opcode_switch_caseD_a:
  piVar7 = ppiVar16[-1];
  ppiStack128 = (int **)piVar7;
  if (piVar7 == (int *)0x0) {
    if ((DAT_103b673c == (int **)0x0) || (DAT_103b673c[0xd] == (int *)0x0)) {
      ppiStack152 = DAT_103b673c;
      ppiStack144 = (int **)FUN_10175160(puVar12,0,0);
      _PyErr_SetObject(ppiStack152,puVar20,ppiStack144);
      piVar7 = (int *)ppiStack128;
      if ((ppiStack144 != (int **)0x0) &&
         (*ppiStack144 = (int *)((int)*ppiStack144 + -1), *ppiStack144 == (int *)0x0)) {
        (*(code *)ppiStack144[1][6])(ppiStack144);
        piVar7 = (int *)ppiStack128;
      }
    }
LAB_101b9b71:
    ppiStack128 = (int **)0x0;
  }
  else {
    iVar6 = *(int *)(piVar7[1] + 0x30);
    if ((iVar6 == 0) || (pcVar9 = *(code **)(iVar6 + 0x1c), pcVar9 == (code *)0x0)) {
      PyErr_Format(PyExc_TypeError,"bad operand type for unary +: \'%.200s\'",
                   *(undefined4 *)(piVar7[1] + 0xc));
      goto LAB_101b9b71;
    }
    ppiStack128 = (int **)(*pcVar9)(piVar7);
  }
  *piVar7 = *piVar7 + -1;
  opcode = ppiStack128;
  if (*piVar7 == 0) {
    (**(code **)(piVar7[1] + 0x18))(piVar7);
    opcode = ppiStack128;
  }
  goto LAB_101b9b8e;
opcode_switch_caseD_1:
  opcode = (int **)ppiVar16[-1];
  local_8c = ppiVar16 + -1;
  *opcode = (int *)((int)*opcode + -1);
  ppiVar13 = local_8c;
  if (*opcode != (int *)0x0) goto LAB_101b8a90;
  piVar7 = opcode[1];
  goto LAB_101b8a80;
}

