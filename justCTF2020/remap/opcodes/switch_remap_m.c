      switch(opcode) {
      case (int **)0x1:
        goto opcode_switch_caseD_1;
      case (int **)0x2:
        if (*(undefined **)(*(int *)(opc_dict + 0x14) + 4) == &PyDict_Type) {
          piVar7_m = (int *)_PyDict_GetItemIdWithError(*(int *)(opc_dict + 0x14));
          iVar4 = local_7c;
          if (piVar7_m != (int *)0x0) {
            FUN_6bce4780();
            *ppiVar16_m = piVar7_m;
            ppiVar16_m = ppiVar16_m + 1;
            puVar15 = local_84;
            local_80 = ppiVar16_m;
            goto LAB_6bce5c00;
          }
          iVar13 = FUN_6bce4930();
          iVar3 = opc_dict;
          if (iVar13 == 0) {
            _PyErr_SetString(iVar4,PyExc_NameError,"__build_class__ not found");
            iVar3 = opc_dict;
          }
        }
        else {
          iVar4 = _PyUnicode_FromId(&DAT_6bedbed4);
          if (iVar4 == 0) goto LAB_6bce8b44;
          ppiVar17 = (int **)PyObject_GetItem(*(undefined4 *)(iVar3 + 0x14),iVar4);
          iVar4 = local_7c;
          if (ppiVar17 != (int **)0x0) goto LAB_6bce7612;
          iVar13 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
          iVar3 = opc_dict;
          if (iVar13 != 0) {
            _PyErr_SetString(iVar4,PyExc_NameError,"__build_class__ not found");
            iVar3 = opc_dict;
          }
        }
        goto LAB_6bce8b44;
      case (int **)0x3:
        local_78 = (int **)ppiVar16_m[-1];
        local_88 = (int **)ppiVar16_m[-2];
        ppiVar16_m = ppiVar16_m + -3;
        piVar7_m = *ppiVar16_m;
        local_80 = ppiVar16_m;
        opcode = (int **)PyObject_SetItem(local_88,local_78,piVar7_m);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        *local_78 = (int *)((int)*local_78 + -1);
        puVar15 = local_84;
        ppiVar17 = opcode;
        if (*local_78 == (int *)0x0) {
          (*(code *)local_78[1][6])(local_78);
          puVar15 = local_84;
          ppiVar17 = opcode;
        }
        goto joined_r0x6bce767b;
      case (int **)0x4:
        local_88 = (int **)ppiVar16_m[-1];
        local_80 = ppiVar16_m + -1;
        piVar7_m = ppiVar16_m[-2];
        local_78 = (int **)PyNumber_Multiply(piVar7_m,local_88);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        *(int ***)(ppiVar16_m + -2) = local_78;
        goto joined_r0x6bce6b6d;
      case (int **)0x5:
        goto opcode_switch_caseD_5;
      case (int **)0x6:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x58,0xc,&DAT_6be8b74c);
        goto LAB_6bce6e23;
      default:
        uVar11 = PyFrame_GetLineNumber(opc_dict,opcode);
        uVar11 = (*local_1c)(2,"XXX lineno: %d, opcode: %d\n",uVar11);
        FUN_6bbbb430(uVar11);
        _PyErr_SetString(local_7c,PyExc_SystemError,"unknown opcode");
        goto LAB_6bce8b44;
      case (int **)0x9:
        piVar7_m = ppiVar16_m[-1];
        ppiVar16_m[-1] = ppiVar16_m[-2];
        ppiVar16_m[-2] = piVar7_m;
        goto LAB_6bce5d85;
      case (int **)0xa:
        *ppiVar16_m = (int *)0x0;
        ppiVar17 = ppiVar16_m + 1;
        local_80 = ppiVar16_m + 1;
        goto LAB_6bce5d85;
      case (int **)0xb:
        piVar7_m = ppiVar16_m[-1];
        puVar20 = &DAT_6be8b6bc;
        uVar11 = 4;
        local_88 = (int **)ppiVar16_m[-2];
        goto LAB_6bce6e17;
      case (int **)0xc:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1ed00(&_Py_NoneStruct,0x14,"** or pow()");
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        *(int ***)(ppiVar16_m + -2) = local_78;
joined_r0x6bce6b6d:
        ppiVar16_m = ppiVar16_m + -1;
        ppiVar17 = local_78;
        goto joined_r0x6bce6c93;
      case (int **)0xf:
        ppiVar17 = (int **)ppiVar16_m[-1];
        ppiVar16_m = ppiVar16_m + -1;
        local_88 = ppiVar17;
        local_80 = ppiVar16_m;
        iVar3 = PyFrame_FastToLocalsWithError(opc_dict);
        ppiVar16 = ppiVar16_m;
        if (iVar3 < 0) {
          FUN_6bce4790(ppiVar17);
          iVar3 = opc_dict;
        }
        else {
          if (*(int *)(opc_dict + 0x1c) != 0) {
            ppiVar17 = (int **)FUN_6bcebef0(ppiVar17);
            PyFrame_LocalsToFast(opc_dict,0);
            FUN_6bce4790(local_88);
            puVar15 = local_84;
            goto joined_r0x6bce767b;
          }
          _PyErr_SetString(local_7c,PyExc_SystemError,"no locals found during \'import *\'");
          FUN_6bce4790(ppiVar17);
          iVar3 = opc_dict;
        }
        goto LAB_6bce8b44;
      case (int **)0x10:
        local_88 = (int **)ppiVar16_m[-1];
        puVar20 = &DAT_6be8b6b8;
        uVar11 = 0x30;
        piVar7_m = ppiVar16_m[-2];
        goto LAB_6bce6e17;
      case (int **)0x11:
        local_88 = (int **)ppiVar16_m[-1];
        local_80 = ppiVar16_m + -1;
        piVar7_m = ppiVar16_m[-2];
        local_78 = (int **)PyObject_GetItem(piVar7_m,local_88);
        goto LAB_6bce6e23;
      case (int **)0x13:
        piVar7_m = ppiVar16_m[-1];
        piVar9 = (int *)FUN_6bcea690(&DAT_6bedbe98);
        iVar3 = opc_dict;
        if (piVar9 == (int *)0x0) goto LAB_6bce8b44;
        ppiVar16_m[-1] = piVar9;
        local_88 = (int **)FUN_6bcea690(&DAT_6bedbee0);
        FUN_6bce4790(piVar7_m);
        ppiVar17 = local_88;
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        local_88 = (int **)FUN_6bce48b0();
        FUN_6bce4790(ppiVar17);
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        *(int ***)ppiVar16_m = local_88;
        ppiVar16_m = ppiVar16_m + 1;
        puVar15 = local_84;
        local_80 = ppiVar16_m;
        if (*(char *)local_84 != '\x05') goto LAB_6bce5c00;
        local_84 = local_84 + 1;
        goto opcode_switch_caseD_5;
      case (int **)0x14:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x68,0x34,&DAT_6be8b728);
        goto LAB_6bce6e23;
      case (int **)0x16:
        ppiVar17 = (int **)ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -1;
        local_80 = ppiVar16;
        iVar3 = _PySys_GetObjectId(&DAT_6bedbe8c);
        if (iVar3 == 0) {
          _PyErr_SetString(local_7c,PyExc_RuntimeError,"lost sys.displayhook");
          goto LAB_6bce5d5e;
        }
        local_88 = (int **)PyObject_CallFunctionObjArgs(iVar3,ppiVar17,0);
        *ppiVar17 = (int *)((int)*ppiVar17 + -1);
        if (*ppiVar17 == (int *)0x0) {
          (*(code *)ppiVar17[1][6])(ppiVar17);
        }
        ppiVar16_m = ppiVar16;
        iVar3 = opc_dict;
        if (local_88 != (int **)0x0) goto LAB_6bce729e;
        goto LAB_6bce8b44;
      case (int **)0x17:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x80,0x78,&DAT_6be8b740);
        goto LAB_6bce6e23;
      case (int **)0x18:
        iVar3 = *(int *)(opc_dict + 0x1c);
        if (iVar3 == 0) {
          _PyErr_Format(local_7c,PyExc_SystemError,"no locals found when setting up annotations");
          iVar3 = opc_dict;
          goto LAB_6bce8b44;
        }
        if (*(undefined **)(iVar3 + 4) == &PyDict_Type) {
          iVar3 = _PyDict_GetItemIdWithError(iVar3);
          if (iVar3 != 0) goto LAB_6bce5c00;
          iVar4 = FUN_6bce4930();
          iVar3 = opc_dict;
          if ((iVar4 == 0) &&
             (local_88 = (int **)PyDict_New(), iVar3 = opc_dict, local_88 != (int **)0x0)) {
            ppiVar17 = (int **)_PyDict_SetItemId(*(undefined4 *)(opc_dict + 0x1c),&DAT_6bedbe74,
                                                 local_88);
            break;
          }
          goto LAB_6bce8b44;
        }
        iVar4 = _PyUnicode_FromId(&DAT_6bedbe74);
        iVar3 = opc_dict;
        if (iVar4 == 0) goto LAB_6bce8b44;
        iVar3 = PyObject_GetItem(*(undefined4 *)(opc_dict + 0x1c),iVar4);
        if (iVar3 != 0) {
          FUN_6bce4790(iVar3);
          puVar15 = local_84;
          goto LAB_6bce5c00;
        }
        iVar13 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
        iVar3 = opc_dict;
        if (iVar13 == 0) goto LAB_6bce8b44;
        _PyErr_Clear(local_7c);
        local_88 = (int **)PyDict_New();
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        ppiVar17 = (int **)PyObject_SetItem(*(undefined4 *)(opc_dict + 0x1c),iVar4,local_88);
        break;
      case (int **)0x19:
        local_88 = (int **)ppiVar16_m[-1];
        puVar20 = &DAT_6be8b6b4;
        uVar11 = 0x2c;
        piVar7_m = ppiVar16_m[-2];
        goto LAB_6bce6e17;
      case (int **)0x1a:
        piVar7_m = ppiVar16_m[-1];
        local_88 = (int **)PyNumber_Positive(piVar7_m);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *(int ***)(ppiVar16_m + -1) = local_88;
        ppiVar17 = local_88;
        goto joined_r0x6bce6c93;
      case (int **)0x1b:
        piVar7_m = ppiVar16_m[-1];
        local_68 = ppiVar16_m + -1;
        local_88 = (int **)PyObject_IsTrue(piVar7_m);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        puVar15 = local_84;
        if (local_88 == (int **)0x0) {
          _Py_TrueStruct = _Py_TrueStruct + 1;
          *local_68 = &_Py_TrueStruct;
        }
        else {
          ppiVar16 = local_68;
          iVar3 = opc_dict;
          if ((int)local_88 < 1) goto LAB_6bce8b44;
          _Py_FalseStruct = _Py_FalseStruct + 1;
          *local_68 = &_Py_FalseStruct;
        }
        goto LAB_6bce5c00;
      case (int **)0x1c:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16_m = ppiVar16_m + -2;
        piVar7_m = *ppiVar16_m;
        local_80 = ppiVar16_m;
        local_78 = (int **)PyObject_DelItem(piVar7_m,local_88);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        puVar15 = local_84;
        ppiVar17 = local_78;
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
          puVar15 = local_84;
          ppiVar17 = local_78;
        }
        goto joined_r0x6bce767b;
      case (int **)0x1d:
        local_88 = (int **)ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        oparg_var14 = (int **)*local_80;
        if ((local_88[1] == (int *)&PyUnicode_Type) && (oparg_var14[1] == (int *)&PyUnicode_Type))
        goto LAB_6bce6db2;
        opcode = (int **)PyNumber_Add(local_88,oparg_var14);
LAB_6bce6dd7:
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        goto LAB_6bce6df3;
      case (int **)0x32:
        local_88 = (int **)ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        oparg_var14 = (int **)*local_80;
        if ((local_88[1] != (int *)&PyUnicode_Type) || (oparg_var14[1] != (int *)&PyUnicode_Type)) {
          opcode = (int **)PyNumber_InPlaceAdd(local_88,oparg_var14);
          goto LAB_6bce6dd7;
        }
LAB_6bce6db2:
        local_80 = ppiVar16_m + -1;
        opcode = (int **)FUN_6bcec550(oparg_var14,opc_dict,puVar15);
LAB_6bce6df3:
        *oparg_var14 = (int *)((int)*oparg_var14 + -1);
        ppiVar16 = opcode;
        ppiVar17 = ppiVar16_m + -1;
        if (*oparg_var14 == (int *)0x0) {
          piVar7_m = oparg_var14[1];
LAB_6bce6d70:
          (*(code *)piVar7_m[6])(oparg_var14);
          ppiVar16 = opcode;
          ppiVar17 = ppiVar16_m + -1;
        }
        goto LAB_6bce6d7c;
      case (int **)0x33:
        goto opcode_switch_caseD_33;
      case (int **)0x34:
        goto LAB_6bce5d85;
      case (int **)0x35:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(100,0x30,&DAT_6be8b730);
        goto LAB_6bce6e23;
      case (int **)0x36:
        piVar7_m = ppiVar16_m[-1];
        piVar9 = ppiVar16_m[-2];
        *piVar7_m = *piVar7_m + 1;
        *piVar9 = *piVar9 + 1;
        ppiVar16_m[1] = piVar7_m;
        *ppiVar16_m = piVar9;
        ppiVar17 = ppiVar16_m + 2;
        local_80 = ppiVar16_m + 2;
        goto LAB_6bce5d85;
      case (int **)0x37:
        goto opcode_switch_caseD_37;
      case (int **)0x38:
        piVar7_m = ppiVar16_m[-1];
        ppiVar16_m[-1] = ppiVar16_m[-2];
        ppiVar16_m[-2] = ppiVar16_m[-3];
        ppiVar16_m[-3] = ppiVar16_m[-4];
        ppiVar16_m[-4] = piVar7_m;
        goto LAB_6bce5d85;
      case (int **)0x39:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x70,0x3c,&DAT_6be8b720);
        goto LAB_6bce6e23;
      case (int **)0x3b:
        piVar7_m = ppiVar16_m[-1];
        ppiVar17 = ppiVar16_m + -1;
        iVar3 = PyErr_GivenExceptionMatches(piVar7_m,PyExc_StopAsyncIteration);
        if (iVar3 == 0) goto LAB_6bce8c61;
        local_88 = (int **)PyFrame_BlockPop(opc_dict);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        iVar3 = (int)local_88;
        if (*(int *)((int)local_88 + 8) + 3 < (int)((int)ppiVar17 - *(int *)(opc_dict + 0x20)) >> 2)
        {
          do {
            piVar7_m = ppiVar17[-1];
            ppiVar17 = ppiVar17 + -1;
            if ((piVar7_m != (int *)0x0) && (*piVar7_m = *piVar7_m + -1, *piVar7_m == 0)) {
              (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
            }
          } while (*(int *)(iVar3 + 8) + 3 < (int)((int)ppiVar17 - *(int *)(opc_dict + 0x20)) >> 2);
        }
        ppiVar16_m = *(int ***)(local_7c + 0x50);
        local_88 = (int **)ppiVar16_m[2];
        piVar7_m = *ppiVar16_m;
        piVar9 = ppiVar16_m[1];
        *ppiVar16_m = ppiVar17[-1];
        ppiVar16_m[1] = ppiVar17[-2];
        ppiVar16_m[2] = ppiVar17[-3];
        if ((piVar7_m != (int *)0x0) && (*piVar7_m = *piVar7_m + -1, *piVar7_m == 0)) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
          (**(code **)(piVar9[1] + 0x18))(piVar9);
        }
        if ((local_88 != (int **)0x0) &&
           (*local_88 = (int *)((int)*local_88 + -1), *local_88 == (int *)0x0)) {
          (*(code *)local_88[1][6])(local_88);
        }
        piVar7_m = ppiVar17[-4];
        ppiVar17 = ppiVar17 + -4;
        *piVar7_m = *piVar7_m + -1;
        puVar15 = local_84;
        local_80 = ppiVar17;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
          puVar15 = local_84;
        }
LAB_6bce5d7e:
        puVar15 = (ushort *)((int)puVar15 + ((uint)oparg & 0xfffffffe));
        goto LAB_6bce5d85;
      case (int **)0x3c:
        piVar7_m = ppiVar16_m[-1];
        *piVar7_m = *piVar7_m + 1;
        *ppiVar16_m = piVar7_m;
        ppiVar17 = ppiVar16_m + 1;
        local_80 = ppiVar16_m + 1;
        goto LAB_6bce5d85;
      case (int **)0x3d:
        ppiVar16 = ppiVar16_m + -1;
        piVar7_m = *ppiVar16;
        if ((*(uint *)(local_5c + 0x1c) & 0x200) != 0) {
          local_64 = piVar7_m;
          piVar7_m = (int *)FUN_6bc58e70();
          *local_64 = *local_64 + -1;
          if (*local_64 == 0) {
            (**(code **)(local_64[1] + 0x18))(local_64);
          }
          iVar3 = opc_dict;
          local_64 = piVar7_m;
          if (piVar7_m == (int *)0x0) goto LAB_6bce8b44;
        }
        *(int ***)(opc_dict + 0x24) = ppiVar16;
        local_64 = piVar7_m;
        goto LAB_6bce93a1;
      case (int **)0x3e:
        local_88 = (int **)ppiVar16_m[-1];
        puVar20 = &DAT_6be8b6b0;
        uVar11 = 0x34;
        piVar7_m = ppiVar16_m[-2];
        goto LAB_6bce6e17;
      case (int **)0x3f:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x6c,0x38,&DAT_6be8b724);
        goto LAB_6bce6e23;
      case (int **)0x40:
        piVar7_m = ppiVar16_m[-1];
        ppiVar17 = ppiVar16_m + -1;
        *piVar7_m = *piVar7_m + -1;
        local_80 = ppiVar17;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        goto LAB_6bce5d85;
      case (int **)0x41:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x50,4,&DAT_6be8b734);
        goto LAB_6bce6e23;
      case (int **)0x42:
        piVar7_m = ppiVar16_m[-1];
        local_10 = &_Py_NoneStruct;
        opcode = (int **)&_Py_NoneStruct;
        if (piVar7_m == (int *)0x0) {
          local_68 = (int **)ppiVar16_m[-2];
          ppiVar16_m[-2] = (int *)0x0;
          piVar7_m = &_Py_NoneStruct;
          ppiVar16 = ppiVar16_m + -1;
        }
        else {
          opcode = (int **)ppiVar16_m[-2];
          local_68 = (int **)ppiVar16_m[-7];
          local_10 = ppiVar16_m[-3];
          ppiVar16_m[-7] = ppiVar16_m[-6];
          ppiVar16_m[-6] = ppiVar16_m[-5];
          ppiVar16_m[-5] = ppiVar16_m[-4];
          ppiVar16_m[-4] = (int *)0x0;
          piVar9 = (int *)(opc_dict + 0x40 + *(int *)(opc_dict + 0x3c) * 0xc);
          *piVar9 = *piVar9 + -1;
        }
        local_14 = (int *)opcode;
        local_18 = piVar7_m;
        opcode = (int **)FUN_6bce4860(3);
        FUN_6bce4790(local_68);
        iVar3 = opc_dict;
        if (opcode == (int **)0x0) goto LAB_6bce8b44;
        FUN_6bce4780();
        *ppiVar16 = piVar7_m;
        *(int ***)(ppiVar16 + 1) = opcode;
        ppiVar16_m = ppiVar16 + 2;
        puVar15 = local_84;
        local_80 = ppiVar16_m;
        if (*(char *)local_84 != '7') goto LAB_6bce5c00;
        local_84 = local_84 + 1;
opcode_switch_caseD_37:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -2;
        local_78 = (int **)*ppiVar16;
        local_80 = ppiVar16;
        if (local_78 == (int **)&_Py_NoneStruct) {
          iVar4 = 0;
        }
        else {
          iVar4 = PyObject_IsTrue(local_88);
        }
        FUN_6bce4790(local_88);
        FUN_6bce4790(local_78);
        iVar3 = opc_dict;
        if (iVar4 < 0) goto LAB_6bce8b44;
        ppiVar16_m = ppiVar16;
        if (0 < iVar4) {
          iVar3 = PyFrame_BlockPop(opc_dict);
          if (*(int *)(iVar3 + 8) + 3 < (int)((int)ppiVar16 - *(int *)(opc_dict + 0x20)) >> 2) {
            do {
              ppiVar16 = ppiVar16 + -1;
              FUN_6bce47c0();
            } while (*(int *)(iVar3 + 8) + 3 < (int)((int)ppiVar16 - *(int *)(opc_dict + 0x20)) >> 2
                    );
          }
          ppiVar16_m = ppiVar16 + -2;
          ppiVar17 = *(int ***)(local_7c + 0x50);
          local_88 = (int **)ppiVar17[1];
          local_78 = (int **)ppiVar17[2];
          *ppiVar17 = ppiVar16[-1];
          ppiVar17[1] = ppiVar16[-2];
          ppiVar17[2] = ppiVar16[-3];
          FUN_6bce47c0();
          FUN_6bce47c0();
          FUN_6bce47c0();
          ppiVar16[-3] = (int *)0x0;
          local_80 = ppiVar16_m;
        }
        puVar15 = local_84;
        if (*(char *)local_84 != '3') goto LAB_6bce5c00;
        local_84 = local_84 + 1;
opcode_switch_caseD_33:
        piVar7_m = ppiVar16_m[-1];
        ppiVar17 = ppiVar16_m + -1;
        puVar15 = local_84;
        local_80 = ppiVar17;
        if (piVar7_m != (int *)0x0) {
          if ((undefined *)piVar7_m[1] != &PyLong_Type) {
LAB_6bce8c61:
            ppiVar16 = ppiVar17 + -2;
            _PyErr_Restore(local_7c,piVar7_m,ppiVar17[-1],*ppiVar16);
            goto LAB_6bce8b90;
          }
          local_88 = (int **)_PyLong_AsInt(piVar7_m);
          *piVar7_m = *piVar7_m + -1;
          if (*piVar7_m == 0) {
            (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
          }
          ppiVar16_m = local_88;
          if (local_88 == (int **)0xffffffff) {
            ppiVar16 = ppiVar17;
            iVar3 = opc_dict;
            if (*(int *)(local_7c + 0x34) != 0) goto LAB_6bce8b44;
            puVar15 = local_6c + -1;
          }
          else {
LAB_6bce6202:
            puVar15 = (ushort *)((int)local_6c + ((uint)ppiVar16_m & 0xfffffffe));
          }
        }
        goto LAB_6bce5d85;
      case (int **)0x43:
        piVar7_m = ppiVar16_m[-2];
        ppiVar16 = ppiVar16_m + -1;
        local_88 = (int **)*ppiVar16;
        local_80 = ppiVar16;
        local_78 = (int **)FUN_6bc1ec40(0x74,&DAT_6be8b70c);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        *(int ***)(ppiVar16_m + -2) = local_78;
        ppiVar16_m = ppiVar16;
        ppiVar17 = local_78;
        goto joined_r0x6bce6c93;
      case (int **)0x44:
        local_88 = (int **)ppiVar16_m[-2];
        ppiVar17 = ppiVar16_m + -1;
        piVar7_m = *ppiVar17;
        local_80 = ppiVar17;
        if ((local_88[1] == (int *)&PyUnicode_Type) &&
           (((*(uint *)((undefined *)piVar7_m[1] + 0x54) & 0x10000000) == 0 ||
            ((undefined *)piVar7_m[1] == &PyUnicode_Type)))) {
          opcode = (int **)PyUnicode_Format(local_88,piVar7_m);
        }
        else {
          opcode = (int **)FUN_6bc1ec40(0xc,&DAT_6be7f9f8);
        }
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        ppiVar16 = opcode;
        if (*local_88 != (int *)0x0) goto LAB_6bce6d7c;
        piVar7_m = local_88[1];
        oparg_var14 = local_88;
        goto LAB_6bce6d70;
      case (int **)0x45:
        piVar7_m = (int *)PyFrame_BlockPop(opc_dict);
        if (*piVar7_m != 0x101) {
          _PyErr_SetString(local_7c,PyExc_SystemError,"popped block is not an except handler");
          goto LAB_6bce8b44;
        }
        ppiVar17 = *(int ***)(local_7c + 0x50);
        local_88 = (int **)ppiVar17[2];
        piVar7_m = *ppiVar17;
        piVar9 = ppiVar17[1];
        *ppiVar17 = ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -2;
        ppiVar16_m = ppiVar16_m + -3;
        ppiVar17[1] = *ppiVar16;
        ppiVar17[2] = *ppiVar16_m;
        local_80 = ppiVar16_m;
        if ((piVar7_m != (int *)0x0) && (*piVar7_m = *piVar7_m + -1, *piVar7_m == 0)) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
          (**(code **)(piVar9[1] + 0x18))(piVar9);
        }
        puVar15 = local_84;
        if (local_88 != (int **)0x0) {
LAB_6bce729e:
          puVar15 = local_84;
          *local_88 = (int *)((int)*local_88 + -1);
          if (*local_88 == (int *)0x0) {
            (*(code *)local_88[1][6])(local_88);
          }
        }
        goto LAB_6bce5c00;
      case (int **)0x46:
        piVar7_m = ppiVar16_m[-2];
        ppiVar16 = ppiVar16_m + -1;
        local_88 = (int **)*ppiVar16;
        local_80 = ppiVar16;
        local_78 = (int **)FUN_6bc1ec40(0x88,&DAT_6be8b708);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        *(int ***)(ppiVar16_m + -2) = local_78;
        ppiVar16_m = ppiVar16;
        ppiVar17 = local_78;
        goto joined_r0x6bce6c93;
      case (int **)0x47:
        piVar7_m = ppiVar16_m[-1];
        ppiVar16_m[-1] = ppiVar16_m[-2];
        ppiVar16_m[-2] = ppiVar16_m[-3];
        ppiVar16_m[-3] = piVar7_m;
        goto LAB_6bce5d85;
      case (int **)0x48:
        piVar7_m = ppiVar16_m[-1];
        local_88 = (int **)PyObject_GetIter(piVar7_m);
        FUN_6bce4790(piVar7_m);
        *(int ***)(ppiVar16_m + -1) = local_88;
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        uVar2 = *local_84;
        if ((uVar2 & 0xff) == 0x62) {
          oparg = (int **)(uint)(uVar2 >> 8);
          local_84 = local_84 + 1;
          goto opcode_switch_caseD_62;
        }
        puVar15 = local_84;
        if ((uVar2 & 0xff) == 0x7a) {
          oparg_var14 = (int **)(uint)(uVar2 >> 8);
          puVar15 = local_84 + 1;
          goto opcode_switch_caseD_7a;
        }
        goto LAB_6bce5c00;
      case (int **)0x49:
        local_88 = (int **)ppiVar16_m[-1];
        local_80 = ppiVar16_m + -1;
        piVar7_m = ppiVar16_m[-2];
        local_78 = (int **)PyNumber_InPlacePower(piVar7_m,local_88,&_Py_NoneStruct);
        goto LAB_6bce6e23;
      case (int **)0x4b:
        local_88 = (int **)ppiVar16_m[-1];
        puVar20 = &DAT_6be7d058;
        uVar11 = 0x3c;
        piVar7_m = ppiVar16_m[-2];
        goto LAB_6bce6e17;
      case (int **)0x4c:
        ppiVar17 = (int **)ppiVar16_m[-1];
        piVar7_m = ppiVar17[1];
        iVar3 = piVar7_m[10];
        if ((iVar3 == 0) || (pcVar10 = *(code **)(iVar3 + 4), pcVar10 == (code *)0x0)) {
          ppiVar16_m[-1] = (int *)0x0;
          iVar3 = piVar7_m[3];
          pcVar19 = "\'async for\' requires an object with __aiter__ method, got %.100s";
        }
        else {
          local_88 = (int **)(*pcVar10)(ppiVar17);
          *ppiVar17 = (int *)((int)*ppiVar17 + -1);
          if (*ppiVar17 == (int *)0x0) {
            (*(code *)ppiVar17[1][6])(ppiVar17);
          }
          if (local_88 == (int **)0x0) {
            ppiVar16_m[-1] = (int *)0x0;
            iVar3 = opc_dict;
            goto LAB_6bce8b44;
          }
          if ((local_88[1][10] != 0) && (*(int *)(local_88[1][10] + 8) != 0)) {
            *(int ***)(ppiVar16_m + -1) = local_88;
            puVar15 = local_84;
            goto LAB_6bce5c00;
          }
          ppiVar16_m[-1] = (int *)0x0;
          iVar3 = local_88[1][3];
          pcVar19 = 
          "\'async for\' received an object from __aiter__ that does not implement __anext__:%.100s"
          ;
          ppiVar17 = local_88;
        }
        _PyErr_Format(local_7c,PyExc_TypeError,pcVar19,iVar3);
        goto LAB_6bce5d5e;
      case (int **)0x4d:
        goto opcode_switch_caseD_4d;
      case (int **)0x4e:
        piVar7_m = ppiVar16_m[-1];
        local_88 = (int **)PyNumber_Negative(piVar7_m);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *(int ***)(ppiVar16_m + -1) = local_88;
        ppiVar17 = local_88;
        goto joined_r0x6bce6c93;
      case (int **)0x4f:
        local_88 = (int **)ppiVar16_m[-1];
        local_80 = ppiVar16_m + -1;
        piVar7_m = ppiVar16_m[-2];
        local_78 = (int **)PyNumber_InPlaceMultiply(piVar7_m,local_88);
        goto LAB_6bce6e23;
      case (int **)0x51:
        piVar7_m = ppiVar16_m[-1];
        local_88 = (int **)PyNumber_Invert(piVar7_m);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *(int ***)(ppiVar16_m + -1) = local_88;
        ppiVar17 = local_88;
        goto joined_r0x6bce6c93;
      case (int **)0x52:
        piVar7_m = ppiVar16_m[-1];
        puVar20 = (undefined *)piVar7_m[1];
        if (puVar20 == &PyAsyncGen_Type) {
          piVar7_m = (int *)(**(code **)(iRam6beca088 + 8))(piVar7_m);
          iVar3 = opc_dict;
          if (piVar7_m == (int *)0x0) goto LAB_6bce8b44;
          *ppiVar16_m = piVar7_m;
          ppiVar16_m = ppiVar16_m + 1;
          local_80 = ppiVar16_m;
          goto LAB_6bce653e;
        }
        if ((*(int *)(puVar20 + 0x28) == 0) ||
           (pcVar10 = *(code **)(*(int *)(puVar20 + 0x28) + 8), pcVar10 == (code *)0x0)) {
          ppiVar17 = *(int ***)(puVar20 + 0xc);
          pcVar19 = "\'async for\' requires an iterator with __anext__ method, got %.100s";
          puVar20 = PyExc_TypeError;
          goto LAB_6bce8b34;
        }
        ppiVar17 = (int **)(*pcVar10)(piVar7_m);
        iVar3 = opc_dict;
        if (ppiVar17 == (int **)0x0) goto LAB_6bce8b44;
        local_88 = (int **)FUN_6bc57fd0();
        if (local_88 == (int **)0x0) {
          _PyErr_FormatFromCause
                    (PyExc_TypeError,
                     "\'async for\' received an invalid object from __anext__: %.100s",
                     ppiVar17[1][3]);
          goto LAB_6bce5d5e;
        }
        *ppiVar17 = (int *)((int)*ppiVar17 + -1);
        if (*ppiVar17 == (int *)0x0) {
          (*(code *)ppiVar17[1][6])(ppiVar17);
        }
        *(int ***)ppiVar16_m = local_88;
        ppiVar16_m = ppiVar16_m + 1;
        puVar15 = local_84;
        local_80 = ppiVar16_m;
        goto LAB_6bce653e;
      case (int **)0x53:
        local_88 = (int **)ppiVar16_m[-1];
        if (local_88[1] == (int *)&PyCoro_Type) {
          if ((*(uint *)(local_5c + 0x1c) & 0x180) != 0) goto LAB_6bce653e;
          FUN_6bce4790(local_88);
          ppiVar16_m[-1] = (int *)0x0;
          _PyErr_SetString(local_7c,PyExc_TypeError,
                           "cannot \'yield from\' a coroutine object in a non-coroutine generator");
          iVar3 = opc_dict;
          goto LAB_6bce8b44;
        }
        if (local_88[1] == (int *)&PyGen_Type) goto LAB_6bce653e;
        ppiVar16 = (int **)PyObject_GetIter(local_88);
        FUN_6bce4790(local_88);
        goto LAB_6bce652f;
      case (int **)0x54:
        piVar7_m = ppiVar16_m[-2];
        ppiVar16 = ppiVar16_m + -1;
        local_88 = (int **)*ppiVar16;
        local_80 = ppiVar16;
        local_78 = (int **)FUN_6bc1ec40(0x78,&DAT_6be8b710);
        *piVar7_m = *piVar7_m + -1;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
        }
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        *(int ***)(ppiVar16_m + -2) = local_78;
        ppiVar16_m = ppiVar16;
        ppiVar17 = local_78;
joined_r0x6bce6c93:
        ppiVar16 = ppiVar16_m;
        puVar15 = local_84;
        iVar3 = opc_dict;
        if (ppiVar17 != (int **)0x0) goto LAB_6bce5c00;
        goto LAB_6bce8b44;
      case (int **)0x55:
        local_88 = (int **)ppiVar16_m[-1];
        puVar20 = &DAT_6be8b6ac;
        uVar11 = 0x38;
        piVar7_m = ppiVar16_m[-2];
LAB_6bce6e17:
        local_80 = ppiVar16_m + -1;
        local_78 = (int **)FUN_6bc1ec40(uVar11,puVar20);
        goto LAB_6bce6e23;
      case (int **)0x56:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x7c,0x74,&DAT_6be8b73c);
        goto LAB_6bce6e23;
      case (int **)0x57:
        local_88 = (int **)ppiVar16_m[-2];
        ppiVar16 = ppiVar16_m + -1;
        piVar7_m = local_88[1];
        piVar9 = *ppiVar16;
        local_80 = ppiVar16;
        if ((piVar7_m == (int *)&PyGen_Type) || (piVar7_m == (int *)&PyCoro_Type)) {
          local_64 = (int *)FUN_6bc570e0(0,0);
        }
        else {
          if (piVar9 == &_Py_NoneStruct) {
            local_64 = (int *)(*(code *)piVar7_m[0x1c])(local_88);
          }
          else {
            local_64 = (int *)_PyObject_CallMethodIdObjArgs(local_88,&DAT_6bedbeec,piVar9,0);
          }
        }
        *piVar9 = *piVar9 + -1;
        if (*piVar9 == 0) {
          (**(code **)(piVar9[1] + 0x18))(piVar9);
        }
        iVar3 = local_7c;
        if (local_64 != (int *)0x0) {
          *(int *)(opc_dict + 0x34) = *(int *)(opc_dict + 0x34) + -2;
          *(int ***)(opc_dict + 0x24) = ppiVar16;
          goto LAB_6bce93a1;
        }
        if ((*(int *)(local_7c + 0x28) != 0) &&
           (iVar4 = PyErr_GivenExceptionMatches
                              (*(undefined4 *)(local_7c + 0x34),PyExc_StopIteration), iVar4 != 0)) {
          FUN_6bceabe0(iVar3,opc_dict);
        }
        iVar4 = _PyGen_FetchStopIterationValue(&local_20);
        iVar3 = opc_dict;
        if (iVar4 < 0) goto LAB_6bce8b44;
        *local_88 = (int *)((int)*local_88 + -1);
        if (*local_88 == (int *)0x0) {
          (*(code *)local_88[1][6])(local_88);
        }
        ppiVar16_m[-2] = local_20;
        ppiVar16_m = ppiVar16;
        puVar15 = local_84;
        goto LAB_6bce5c00;
      case (int **)0x58:
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)*local_80;
        local_78 = (int **)FUN_6bc1f4c0(0x8c,0x88,&DAT_6be8b738);
        goto LAB_6bce6e23;
      case (int **)0x59:
        local_64 = ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -1;
        goto LAB_6bce9376;
      case (int **)0x5a:
        piVar7_m = ppiVar16_m[-1];
        local_68 = (int **)0x0;
        iVar4 = FUN_6bc71e90(&local_68);
        iVar3 = opc_dict;
        if (local_68 == (int **)0x0) goto LAB_6bce8b44;
        if (iVar4 == 0) {
          ppiVar16_m[-1] = (int *)0x0;
          FUN_6bce4790(piVar7_m);
          *(int ***)ppiVar16_m = local_68;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
        }
        else {
          *ppiVar16_m = piVar7_m;
          *(int ***)(ppiVar16_m + -1) = local_68;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
        }
        goto LAB_6bce5c00;
      case (int **)0x5b:
        ppiVar17 = (int **)PyTuple_New(oparg_var14);
        iVar3 = opc_dict;
        if (ppiVar17 == (int **)0x0) goto LAB_6bce8b44;
        iVar3 = (int)oparg + -1;
        if (iVar3 < 0) goto LAB_6bce7612;
        ppiVar16 = ppiVar17 + (int)oparg + 2;
        do {
          local_80 = ppiVar16_m;
          *ppiVar16 = local_80[-1];
          iVar3 = iVar3 + -1;
          ppiVar16 = ppiVar16 + -1;
          ppiVar16_m = local_80 + -1;
        } while (-1 < iVar3);
        *(int ***)(local_80 + -1) = ppiVar17;
        ppiVar16_m = local_80;
        puVar15 = local_84;
        goto LAB_6bce5c00;
      case (int **)0x5c:
        opcode = (int **)PyDict_New();
        iVar3 = opc_dict;
        if (opcode == (int **)0x0) goto LAB_6bce8b44;
        local_88 = oparg;
        if ((int)oparg < 1) goto LAB_6bce83b9;
        ppiVar17 = ppiVar16_m + (int)oparg * 0x3fffffff;
        goto LAB_6bce8381;
      case (int **)0x5d:
        PyFrame_BlockSetup(opc_dict,0x5d,
                           (int **)((int)oparg_var14 + ((int)((int)puVar15 - (int)local_6c) >> 1) * 2),
                           (int)((int)ppiVar16_m - *(int *)(opc_dict + 0x20)) >> 2);
        goto LAB_6bce5c00;
      case (int **)0x5e:
        ppiVar17 = (int **)FUN_6bcebca0(*(undefined4 *)(local_60 + 0xc + (int)oparg_var14 * 4));
        goto LAB_6bce68f0;
      case (int **)0x5f:
        ppiVar16_m = ppiVar16_m + -1;
        local_88 = (int **)*ppiVar16_m;
        local_80 = ppiVar16_m;
        ppiVar17 = (int **)PyObject_SetAttr(local_88,*(undefined4 *)
                                                      (local_60 + 0xc + (int)oparg_var14 * 4),0);
        break;
      case (int **)0x60:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -2;
        piVar7_m = *ppiVar16;
        local_78 = (int **)PyFunction_NewWithQualName
                                     (piVar7_m,*(undefined4 *)(opc_dict + 0x18),local_88);
        FUN_6bce4790(piVar7_m);
        FUN_6bce4790(local_88);
        iVar3 = opc_dict;
        if (local_78 == (int **)0x0) goto LAB_6bce8b44;
        if (((uint)oparg & 8) != 0) {
          ppiVar16 = ppiVar16_m + -3;
          local_78[6] = ppiVar16_m[-3];
        }
        if (((uint)oparg & 4) != 0) {
          ppiVar16_m = ppiVar16 + -1;
          ppiVar16 = ppiVar16 + -1;
          local_78[0xc] = *ppiVar16_m;
        }
        if (((uint)oparg & 2) != 0) {
          ppiVar16_m = ppiVar16 + -1;
          ppiVar16 = ppiVar16 + -1;
          local_78[5] = *ppiVar16_m;
        }
        if (((uint)oparg & 1) != 0) {
          ppiVar16_m = ppiVar16 + -1;
          ppiVar16 = ppiVar16 + -1;
          local_78[4] = *ppiVar16_m;
        }
        *(int ***)ppiVar16 = local_78;
        ppiVar16_m = ppiVar16 + 1;
        puVar15 = local_84;
        local_80 = ppiVar16 + 1;
        goto LAB_6bce5c00;
      case (int **)0x61:
        goto opcode_switch_caseD_61;
      case (int **)0x62:
opcode_switch_caseD_62:
        piVar7_m = ppiVar16_m[-1];
        local_88 = ppiVar16_m + -1;
        piVar9 = (int *)(**(code **)(piVar7_m[1] + 0x70))(piVar7_m);
        if (piVar9 == (int *)0x0) {
          iVar3 = FUN_6bce4930();
          if (iVar3 != 0) {
            iVar13 = _PyErr_ExceptionMatches(local_7c,PyExc_StopIteration);
            iVar4 = local_7c;
            iVar3 = opc_dict;
            if (iVar13 == 0) goto LAB_6bce8b44;
            if (*(int *)(local_7c + 0x28) != 0) {
              FUN_6bceabe0(local_7c,opc_dict);
            }
            _PyErr_Clear(iVar4);
          }
          ppiVar16_m = local_88;
          local_80 = local_88;
          FUN_6bce4790(piVar7_m);
          puVar15 = (ushort *)((int)local_84 + ((uint)oparg & 0xfffffffe));
          if (*(char *)((int)local_84 + ((uint)oparg & 0xfffffffe)) == 'M') {
            puVar15 = puVar15 + 1;
opcode_switch_caseD_4d:
            PyFrame_BlockPop(opc_dict);
          }
        }
        else {
          *ppiVar16_m = piVar9;
          ppiVar16_m = ppiVar16_m + 1;
          uVar2 = *local_84;
          if ((uVar2 & 0xff) == (ushort)local_28) {
            oparg_var14 = (int **)(uint)(uVar2 >> 8);
            puVar15 = local_84 + 1;
            goto opcode_switch_caseD_89;
          }
          puVar15 = local_84;
          local_80 = ppiVar16_m;
          if ((uVar2 & 0xff) == 0x6a) {
            oparg_var14 = (int **)(uint)(uVar2 >> 8);
            local_84 = local_84 + 1;
            goto opcode_switch_caseD_6a;
          }
        }
        goto LAB_6bce5c00;
      case (int **)0x64:
        local_88 = (int **)PyUnicode_New(0,0);
        ppiVar17 = oparg;
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        opcode = (int **)_PyUnicode_JoinArray(local_88,ppiVar16_m + (int)oparg * 0x3fffffff,oparg);
        FUN_6bce4790(local_88);
        iVar3 = opc_dict;
        if (opcode != (int **)0x0) goto joined_r0x6bce7d11;
        goto LAB_6bce8b44;
      case (int **)0x65:
      case (int **)0x8f:
      case (int **)0x94:
        local_80 = (int **)PyList_New(0);
        iVar3 = opc_dict;
        if (local_80 == (int **)0x0) goto LAB_6bce8b44;
        local_68 = oparg;
        if ((int)oparg < 1) goto LAB_6bce7e4a;
        local_78 = ppiVar16_m + (int)oparg * 0x3fffffff;
        goto LAB_6bce7e08;
      case (int **)0x66:
        puVar15 = (ushort *)((int)puVar15 + ((uint)oparg_var14 & 0xfffffffe));
        goto LAB_6bce5d85;
      case (int **)0x67:
        piVar7_m = ppiVar16_m[-1];
        local_88 = ppiVar16_m + -1;
        if (piVar7_m == &_Py_FalseStruct) goto LAB_6bce625c;
        if (piVar7_m == &_Py_TrueStruct) {
          puVar15 = (ushort *)((int)local_6c + ((uint)oparg_var14 & 0xfffffffe));
          goto LAB_6bce5d85;
        }
        iVar4 = PyObject_IsTrue(piVar7_m);
        ppiVar17 = local_88;
        if (iVar4 < 1) {
          iVar3 = opc_dict;
          if (iVar4 != 0) goto LAB_6bce8b44;
          local_80 = local_88;
          FUN_6bce4790(piVar7_m);
          ppiVar16_m = ppiVar17;
          puVar15 = local_84;
        }
        else {
          puVar15 = (ushort *)((int)local_6c + ((uint)oparg & 0xfffffffe));
        }
        goto LAB_6bce5c00;
      case (int **)0x68:
        opcode = (int **)PySet_New(0);
        iVar3 = opc_dict;
        if (opcode == (int **)0x0) goto LAB_6bce8b44;
        local_88 = oparg;
        if ((int)oparg < 1) goto joined_r0x6bce7fd4;
        ppiVar17 = ppiVar16_m + (int)oparg * 0x3fffffff;
        goto LAB_6bce7fa3;
      case (int **)0x69:
        local_68 = ppiVar16_m + -1;
        local_78 = (int **)*local_68;
        if ((local_78[1] == (int *)&PyTuple_Type) && ((int **)local_78[2] == oparg_var14)) {
          opcode = (int **)_PyDict_NewPresized(oparg_var14);
          iVar3 = opc_dict;
          if (opcode == (int **)0x0) goto LAB_6bce8b44;
          local_88 = oparg;
          if ((int)oparg < 1) goto LAB_6bce8258;
          ppiVar16_m = (int **)((int)ppiVar16_m - ((int)oparg * 4 + 4));
          local_78 = local_78 + 3;
          goto LAB_6bce8220;
        }
        pcVar19 = "bad BUILD_CONST_KEY_MAP keys argument";
LAB_6bce8fb6:
        _PyErr_SetString(local_7c,PyExc_SystemError,pcVar19);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x6a:
opcode_switch_caseD_6a:
        local_68 = (int **)ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -1;
        local_80 = ppiVar16;
        if ((local_68[1] == (int *)&PyTuple_Type) && ((int **)local_68[2] == oparg_var14))
        goto joined_r0x6bce6940;
        if ((local_68[1] == (int *)&PyList_Type) && ((int **)local_68[2] == oparg_var14)) {
          local_88 = (int **)local_68[3];
          while (ppiVar16_m = ppiVar16, oparg_var14 != (int **)0x0) {
            piVar7_m = local_88[(int)oparg_var14 + -1];
            oparg = (int **)((int)oparg_var14 + -1);
            FUN_6bce4780();
            *ppiVar16 = piVar7_m;
            ppiVar16 = ppiVar16 + 1;
            oparg_var14 = oparg;
          }
          goto LAB_6bce85d4;
        }
        iVar3 = FUN_6bcea930(oparg_var14,0xffffffff,ppiVar16 + (int)oparg_var14);
        ppiVar16_m = ppiVar16 + (int)oparg_var14;
        if (iVar3 != 0) goto LAB_6bce85d4;
        FUN_6bce4790(local_68);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x6b:
        local_88 = (int **)ppiVar16_m[-1];
        local_3c = ppiVar16_m + -1;
        piVar7_m = (int *)FUN_6bceb600(oparg_var14,local_88);
        *local_3c = piVar7_m;
        ppiVar16_m = local_3c + 1;
        local_80 = ppiVar16_m;
        FUN_6bce4790(local_88);
        bVar18 = piVar7_m == (int *)0x0;
        goto LAB_6bce6d81;
      case (int **)0x6c:
        local_88 = (int **)ppiVar16_m[-1];
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        local_78 = (int **)FUN_6bcebb60(*(undefined4 *)(local_60 + 0xc + (int)oparg_var14 * 4),local_88
                                        ,piVar7_m);
        FUN_6bce4790(piVar7_m);
        FUN_6bce4790(local_88);
        ppiVar16 = local_78;
        ppiVar17 = ppiVar16_m + -1;
        goto LAB_6bce6d7c;
      case (int **)0x6d:
        goto opcode_switch_caseD_6d;
      case (int **)0x6e:
        ppiVar17 = *(int ***)(local_60 + 0xc + (int)oparg_var14 * 4);
        iVar3 = PyDict_DelItem(*(undefined4 *)(opc_dict + 0x18),ppiVar17);
        puVar15 = local_84;
        if (iVar3 == 0) goto LAB_6bce5c00;
LAB_6bce7807:
        iVar4 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
        iVar3 = opc_dict;
        if (iVar4 != 0) goto LAB_6bce7822;
        goto LAB_6bce8b44;
      case (int **)0x6f:
        piVar7_m = (int *)0x0;
        if (oparg_var14 != (int **)0x0) {
          if (oparg_var14 != (int **)0x1) {
            if (oparg_var14 != (int **)0x2) {
              pcVar19 = "bad RAISE_VARARGS oparg";
              goto LAB_6bce8fb6;
            }
            piVar7_m = ppiVar16_m[-1];
            ppiVar16_m = ppiVar16_m + -1;
          }
          ppiVar16 = ppiVar16_m + -1;
        }
        iVar4 = FUN_6bcea700(piVar7_m);
        iVar3 = opc_dict;
        if (iVar4 == 0) goto LAB_6bce8b44;
        goto LAB_6bce8b90;
      case (int **)0x70:
        iVar3 = *(int *)(local_50 + (int)oparg_var14 * 4);
        iVar4 = *(int *)(iVar3 + 8);
        if (iVar4 == 0) goto LAB_6bce8e9c;
        *(undefined4 *)(iVar3 + 8) = 0;
        FUN_6bce4790(iVar4);
        goto LAB_6bce5c00;
      case (int **)0x71:
        oparg = *(int ***)(opc_dict + 0x18);
        if ((oparg[1] != (int *)&PyDict_Type) ||
           (*(undefined **)(*(int *)(opc_dict + 0x14) + 4) != &PyDict_Type)) {
          ppiVar17 = *(int ***)(local_60 + 0xc + (int)oparg_var14 * 4);
          piVar7_m = (int *)PyObject_GetItem(oparg,ppiVar17);
          if (piVar7_m == (int *)0x0) {
            iVar4 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
            iVar3 = opc_dict;
            if (iVar4 == 0) goto LAB_6bce8b44;
            _PyErr_Clear(local_7c);
            piVar7_m = (int *)PyObject_GetItem(*(undefined4 *)(opc_dict + 0x14),ppiVar17);
            if (piVar7_m == (int *)0x0) goto LAB_6bce7807;
          }
          *ppiVar16_m = piVar7_m;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
          goto LAB_6bce5c00;
        }
        ppiVar17 = (int **)0x0;
        if (((((*(int *)(local_5c + 0x5c) != 0) &&
              (bVar1 = *(byte *)(((int)((int)puVar15 - (int)local_6c) >> 1) +
                                *(int *)(local_5c + 0x58)), bVar1 != 0)) &&
             (ppiVar17 = (int **)(*(int *)(local_5c + 0x5c) + -0x20 + (uint)bVar1 * 0x20),
             opcode = ppiVar17, ppiVar17 != (int **)0x0)) &&
            (('\0' < *(char *)(ppiVar17 + 6) && (ppiVar17[2] == oparg[4])))) &&
           ((ppiVar17[3] == oparg[5] &&
            ((ppiVar17[4] == *(int **)(*(int *)(opc_dict + 0x14) + 0x10) &&
             (ppiVar17[5] == *(int **)(*(int *)(opc_dict + 0x14) + 0x14))))))) {
          piVar7_m = *ppiVar17;
          FUN_6bce4780();
          *ppiVar16_m = piVar7_m;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
          goto LAB_6bce5c00;
        }
        local_78 = *(int ***)(local_60 + 0xc + (int)oparg_var14 * 4);
        local_88 = (int **)FUN_6bc438b0(local_78);
        if (local_88 == (int **)0x0) {
          iVar4 = FUN_6bbbb560();
          iVar3 = opc_dict;
          ppiVar17 = local_78;
          if (*(int *)(iVar4 + 0x34) == 0) {
LAB_6bce7822:
            FUN_6bcec430("name \'%.200s\' is not defined",ppiVar17);
            iVar3 = opc_dict;
          }
          goto LAB_6bce8b44;
        }
        if (ppiVar17 != (int **)0x0) {
          *(undefined *)(ppiVar17 + 6) = 1;
          iVar3 = *(int *)(opc_dict + 0x18);
          ppiVar17[2] = *(int **)(iVar3 + 0x10);
          ppiVar17[3] = *(int **)(iVar3 + 0x14);
          iVar3 = *(int *)(opc_dict + 0x14);
          ppiVar17[4] = *(int **)(iVar3 + 0x10);
          ppiVar17[5] = *(int **)(iVar3 + 0x14);
          *(int ***)ppiVar17 = local_88;
        }
        FUN_6bce4780();
        *(int ***)ppiVar16_m = local_88;
        ppiVar16_m = ppiVar16_m + 1;
        puVar15 = local_84;
        local_80 = ppiVar16_m;
        goto LAB_6bce5c00;
      case (int **)0x72:
        if (*(int *)(local_4c + (int)oparg_var14 * 4) != 0) {
          *(undefined4 *)(local_4c + (int)oparg_var14 * 4) = 0;
          FUN_6bce47c0();
          goto LAB_6bce5c00;
        }
        uVar11 = PyTuple_GetItem(*(undefined4 *)(local_5c + 0x30),oparg_var14);
        FUN_6bcec430("local variable \'%.200s\' referenced before assignment",uVar11);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x73:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -1;
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16;
        local_78 = (int **)FUN_6bceba00(piVar7_m,local_88);
        FUN_6bce4790(piVar7_m);
        FUN_6bce4790(local_88);
        *(int ***)(ppiVar16_m + -2) = local_78;
        iVar3 = opc_dict;
        if (local_78 == (int **)0x0) goto LAB_6bce8b44;
        uVar2 = *local_84;
        if ((uVar2 & 0xff) == (ushort)local_2c) {
          oparg = (int **)(uint)(uVar2 >> 8);
          local_84 = local_84 + 1;
          goto opcode_switch_caseD_82;
        }
        ppiVar16_m = ppiVar16;
        puVar15 = local_84;
        if ((uVar2 & 0xff) == 0x83) {
          oparg = (int **)(uint)(uVar2 >> 8);
          local_84 = local_84 + 1;
          goto opcode_switch_caseD_83;
        }
        goto LAB_6bce5c00;
      case (int **)0x74:
        piVar7_m = ppiVar16_m[-1];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)PyList_Append(local_80[(int)oparg_var14 * 0x3fffffff],piVar7_m);
        goto LAB_6bce6f11;
      case (int **)0x7a:
opcode_switch_caseD_7a:
        local_40 = ppiVar16_m;
        ppiVar17 = (int **)FUN_6bceb600(oparg_var14,0);
        ppiVar16_m = local_40;
        goto LAB_6bce68f0;
      case (int **)0x7c:
        if (oparg_var14 == (int **)0x3) {
          local_88 = (int **)ppiVar16_m[-1];
          ppiVar16_m = ppiVar16_m + -1;
        }
        else {
          local_88 = (int **)0x0;
        }
        local_78 = (int **)ppiVar16_m[-1];
        piVar7_m = ppiVar16_m[-2];
        local_80 = ppiVar16_m + -1;
        opcode = (int **)PySlice_New(piVar7_m,local_78,local_88);
        FUN_6bce4790(piVar7_m);
        FUN_6bce4790(local_78);
        FUN_6bce47c0();
        ppiVar16 = opcode;
        ppiVar17 = ppiVar16_m + -1;
        goto LAB_6bce6d7c;
      case (int **)0x7d:
        ppiVar16 = ppiVar16_m + -1;
        uVar11 = *(undefined4 *)(local_60 + 0xc + (int)oparg_var14 * 4);
        piVar7_m = *ppiVar16;
        iVar3 = *(int *)(opc_dict + 0x1c);
        local_80 = ppiVar16;
        if (iVar3 != 0) {
          if (*(undefined **)(iVar3 + 4) == &PyDict_Type) {
            opcode = (int **)PyDict_SetItem();
          }
          else {
            opcode = (int **)PyObject_SetItem(iVar3,uVar11,piVar7_m);
          }
          FUN_6bce4790(piVar7_m);
          ppiVar16_m = ppiVar16;
          puVar15 = local_84;
          ppiVar17 = opcode;
          goto joined_r0x6bce767b;
        }
        _PyErr_Format(local_7c,PyExc_SystemError,"no locals found when storing %R",uVar11);
        FUN_6bce4790(piVar7_m);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x7e:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16_m = ppiVar16_m + -2;
        piVar7_m = *ppiVar16_m;
        local_80 = ppiVar16_m;
        local_78 = (int **)PyObject_SetAttr(local_88,*(undefined4 *)
                                                      (local_60 + 0xc + (int)oparg_var14 * 4),piVar7_m);
        FUN_6bce4790(piVar7_m);
        FUN_6bce4790(local_88);
        puVar15 = local_84;
        ppiVar17 = local_78;
        goto joined_r0x6bce767b;
      case (int **)0x82:
opcode_switch_caseD_82:
        piVar7_m = ppiVar16[-1];
        ppiVar17 = ppiVar16 + -1;
        local_80 = ppiVar17;
        if (piVar7_m == &_Py_TrueStruct) goto LAB_6bce6262;
        if (piVar7_m == &_Py_FalseStruct) goto LAB_6bce61f1;
        local_88 = (int **)PyObject_IsTrue(piVar7_m);
        FUN_6bce4790(piVar7_m);
        ppiVar16_m = ppiVar17;
        puVar15 = local_84;
        oparg_var14 = local_88;
        if ((int)local_88 < 1) goto LAB_6bce67ef;
        goto LAB_6bce5c00;
      case (int **)0x83:
opcode_switch_caseD_83:
        piVar7_m = ppiVar16[-1];
        ppiVar17 = ppiVar16 + -1;
        local_80 = ppiVar17;
        if (piVar7_m == &_Py_FalseStruct) goto LAB_6bce6262;
        if (piVar7_m == &_Py_TrueStruct) {
LAB_6bce61f1:
          local_80 = ppiVar17;
          FUN_6bce4790();
          ppiVar16_m = oparg;
          goto LAB_6bce6202;
        }
        local_88 = (int **)PyObject_IsTrue(piVar7_m);
        FUN_6bce4790(piVar7_m);
        ppiVar16_m = ppiVar17;
        puVar15 = local_84;
        ppiVar17 = local_88;
        if ((int)local_88 < 1) goto joined_r0x6bce767b;
        puVar15 = (ushort *)((int)local_6c + ((uint)oparg & 0xfffffffe));
        goto LAB_6bce5c00;
      case (int **)0x84:
        piVar7_m = ppiVar16_m[-1];
        local_88 = (int **)PyObject_GetAttr(piVar7_m,*(undefined4 *)
                                                     (local_60 + 0xc + (int)oparg_var14 * 4));
        FUN_6bce4790(piVar7_m);
        ppiVar16 = local_88;
        goto LAB_6bce6d7c;
      case (int **)0x85:
        opcode = (int **)_PyDict_NewPresized(oparg_var14);
        iVar3 = opc_dict;
        if (opcode == (int **)0x0) goto LAB_6bce8b44;
        local_88 = oparg;
        if ((int)oparg < 1) goto LAB_6bce8074;
        ppiVar17 = ppiVar16_m + (int)oparg * 0x3ffffffe;
        goto LAB_6bce8040;
      case (int **)0x87:
        local_48 = ppiVar16_m;
        if (*(int **)((int)ppiVar16_m - ((int)oparg_var14 * 4 + 8)) == (int *)0x0) {
          ppiVar17 = (int **)FUN_6bceb600(oparg_var14,0);
          ppiVar16_m = local_48 + -1;
        }
        else {
          ppiVar17 = (int **)FUN_6bceb600((int)oparg_var14 + 1,0);
          ppiVar16_m = local_48;
        }
LAB_6bce68f0:
        *(int ***)ppiVar16_m = ppiVar17;
        ppiVar16_m = ppiVar16_m + 1;
        local_80 = ppiVar16_m;
        goto joined_r0x6bce767b;
      case (int **)0x88:
        ppiVar17 = *(int ***)(local_60 + 0xc + (int)oparg_var14 * 4);
        if (*(int *)(opc_dict + 0x1c) == 0) {
          pcVar19 = "no locals when deleting %R";
          puVar20 = PyExc_SystemError;
          goto LAB_6bce8b34;
        }
        iVar3 = PyObject_DelItem(*(int *)(opc_dict + 0x1c),ppiVar17);
        puVar15 = local_84;
        if (iVar3 != 0) goto LAB_6bce7822;
        goto LAB_6bce5c00;
      case (int **)0x89:
opcode_switch_caseD_89:
        ppiVar17 = ppiVar16_m + -1;
        local_88 = *(int ***)(local_4c + (int)oparg_var14 * 4);
        *(int **)(local_4c + (int)oparg_var14 * 4) = *ppiVar17;
        local_80 = ppiVar17;
        if ((local_88 != (int **)0x0) &&
           (*local_88 = (int *)((int)*local_88 + -1), *local_88 == (int *)0x0)) {
          (*(code *)local_88[1][6])(local_88);
        }
        goto LAB_6bce5d85;
      case (int **)0x8a:
        oparg = (int **)0x0;
        if (((uint)oparg_var14 & 1) != 0) {
          oparg = (int **)ppiVar16_m[-1];
          ppiVar17 = ppiVar16_m + -1;
          if (oparg[1] != (int *)&PyDict_Type) {
            ppiVar16_m = (int **)PyDict_New();
            ppiVar16 = ppiVar17;
            iVar3 = opc_dict;
            if (ppiVar16_m == (int **)0x0) goto LAB_6bce8b44;
            iVar3 = _PyDict_MergeEx(ppiVar16_m,oparg,2);
            if (iVar3 < 0) {
              FUN_6bce4790(ppiVar16_m);
              ppiVar16_m = oparg;
              FUN_6bcec2a0(oparg);
              FUN_6bce4790(ppiVar16_m);
              iVar3 = opc_dict;
              goto LAB_6bce8b44;
            }
            FUN_6bce4790(oparg);
            oparg = ppiVar16_m;
          }
        }
        oparg_var14 = (int **)ppiVar17[-1];
        ppiVar16_m = ppiVar17 + -1;
        local_88 = (int **)ppiVar17[-2];
        local_80 = ppiVar16_m;
        local_68 = oparg_var14;
        if (oparg_var14[1] != (int *)&PyTuple_Type) {
          iVar3 = FUN_6bcec210(oparg_var14);
          ppiVar16 = ppiVar16_m;
          if (iVar3 < 0) {
            FUN_6bce4790(oparg_var14);
            iVar3 = opc_dict;
            goto LAB_6bce8b44;
          }
          local_68 = (int **)PySequence_Tuple(oparg_var14);
          FUN_6bce4790(oparg_var14);
          iVar3 = opc_dict;
          if (local_68 == (int **)0x0) goto LAB_6bce8b44;
        }
        piVar7_m = (int *)FUN_6bceb6d0(local_68,oparg);
        FUN_6bce4790(local_88);
        FUN_6bce4790(local_68);
        FUN_6bce47c0();
        ppiVar17[-2] = piVar7_m;
        bVar18 = piVar7_m == (int *)0x0;
        goto LAB_6bce6d81;
      case (int **)0x8d:
        piVar7_m = *(int **)(local_4c + (int)oparg_var14 * 4);
        if (piVar7_m != (int *)0x0) {
          *piVar7_m = *piVar7_m + 1;
          *ppiVar16_m = piVar7_m;
          ppiVar17 = ppiVar16_m + 1;
          local_80 = ppiVar16_m + 1;
          goto LAB_6bce5d85;
        }
        iVar4 = PyTuple_GetItem(*(undefined4 *)(local_5c + 0x30),oparg_var14);
        puVar20 = PyExc_UnboundLocalError;
        iVar3 = opc_dict;
        if ((iVar4 != 0) &&
           (ppiVar17 = (int **)PyUnicode_AsUTF8AndSize(iVar4,0), iVar3 = opc_dict,
           ppiVar17 != (int **)0x0)) {
          pcVar19 = "local variable \'%.200s\' referenced before assignment";
LAB_6bce8b34:
          _PyErr_Format(local_7c,puVar20,pcVar19,ppiVar17);
          iVar3 = opc_dict;
        }
        goto LAB_6bce8b44;
      case (int **)0x8e:
        ppiVar16_m = ppiVar16_m + -1;
        *(int **)(*(int *)(local_50 + (int)oparg_var14 * 4) + 8) = *ppiVar16_m;
        local_80 = ppiVar16_m;
        FUN_6bce47c0();
        goto LAB_6bce5c00;
      case (int **)0x90:
        piVar7_m = ppiVar16_m[-1];
        local_88 = ppiVar16_m + -1 + ((uint)oparg_var14 & 0xff) + 1 + ((int)oparg_var14 >> 8);
        iVar3 = FUN_6bcea930((uint)oparg_var14 & 0xff,(int)oparg_var14 >> 8,local_88);
        ppiVar16_m = local_88;
        if (iVar3 != 0) {
          local_80 = local_88;
          FUN_6bce4790(piVar7_m);
          puVar15 = local_84;
          goto LAB_6bce5c00;
        }
        FUN_6bce4790(piVar7_m);
        ppiVar16 = ppiVar16_m + -1;
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x91:
        piVar7_m = ppiVar16_m[-1];
        local_88 = (int **)FUN_6bcea690(&DAT_6bedbf04);
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        piVar9 = (int *)FUN_6bcea690(&DAT_6bedbebc);
        if (piVar9 == (int *)0x0) {
          FUN_6bce4790(local_88);
          iVar3 = opc_dict;
          goto LAB_6bce8b44;
        }
        ppiVar16_m[-1] = piVar9;
        FUN_6bce4790(piVar7_m);
        ppiVar17 = local_88;
        local_88 = (int **)FUN_6bce48b0();
        FUN_6bce4790(ppiVar17);
        ppiVar17 = local_88;
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        PyFrame_BlockSetup(opc_dict,0x5d,
                           (int **)((int)oparg + ((int)((int)local_84 - (int)local_6c) >> 1) * 2),
                           (int)((int)ppiVar16_m - *(int *)(opc_dict + 0x20)) >> 2);
        *(int ***)ppiVar16_m = ppiVar17;
        ppiVar16_m = ppiVar16_m + 1;
        puVar15 = local_84;
        local_80 = ppiVar16_m;
        goto LAB_6bce5c00;
      case (int **)0x92:
        if (*(undefined **)(*(int *)(opc_dict + 0x1c) + 4) == &PyDict_Type) {
          piVar7_m = (int *)PyDict_GetItemWithError();
          if (piVar7_m != (int *)0x0) {
            FUN_6bce4780();
            *ppiVar16_m = piVar7_m;
            ppiVar16_m = ppiVar16_m + 1;
            puVar15 = local_84;
            local_80 = ppiVar16_m;
            goto LAB_6bce5c00;
          }
          iVar4 = FUN_6bce4930();
          iVar3 = opc_dict;
          if (iVar4 != 0) goto LAB_6bce8b44;
        }
        else {
          ppiVar17 = (int **)PyObject_GetItem(*(int *)(opc_dict + 0x1c),
                                              *(undefined4 *)
                                               (*(int *)(local_5c + 0x34) + 0xc +
                                               (int)((int)oparg_var14 -
                                                    *(int *)(*(int *)(local_5c + 0x38) + 8)) * 4));
          iVar4 = local_7c;
          if (ppiVar17 != (int **)0x0) goto LAB_6bce7612;
          iVar13 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
          iVar3 = opc_dict;
          if (iVar13 == 0) goto LAB_6bce8b44;
          _PyErr_Clear(iVar4);
        }
        piVar7_m = *(int **)(*(int *)(local_50 + (int)oparg * 4) + 8);
        if (piVar7_m != (int *)0x0) {
          FUN_6bce4780();
          *ppiVar16_m = piVar7_m;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
          goto LAB_6bce5c00;
        }
        FUN_6bcec470(oparg);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x93:
        piVar7_m = *(int **)(*(int *)(local_50 + (int)oparg_var14 * 4) + 8);
        if (piVar7_m != (int *)0x0) {
          FUN_6bce4780();
          *ppiVar16_m = piVar7_m;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
          goto LAB_6bce5c00;
        }
LAB_6bce8e9c:
        FUN_6bcec470(oparg_var14);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x95:
        if (((uint)oparg_var14 & 4) == 0) {
          local_68 = (int **)0x0;
        }
        else {
          local_68 = (int **)ppiVar16_m[-1];
          ppiVar16_m = ppiVar16_m + -1;
        }
        ppiVar17 = (int **)ppiVar16_m[-1];
        ppiVar16 = ppiVar16_m + -1;
        local_78 = ppiVar16_m;
        switch((uint)oparg_var14 & 3) {
        case 1:
          pcVar10 = PyObject_Str;
          break;
        case 2:
          pcVar10 = PyObject_Repr;
          break;
        case 3:
          pcVar10 = PyObject_ASCII;
          break;
        case 0:
          goto switchD_101a8a6b_caseD_0;
        }
        local_88 = ppiVar17;
        local_88 = (int **)(*pcVar10)(ppiVar17);
        FUN_6bce4790(ppiVar17);
        ppiVar17 = local_88;
        if (local_88 == (int **)0x0) {
          FUN_6bce47c0();
          iVar3 = opc_dict;
          goto LAB_6bce8b44;
        }
switchD_101a8a6b_caseD_0:
        local_88 = ppiVar17;
        if ((ppiVar17[1] != (int *)&PyUnicode_Type) || (local_68 != (int **)0x0)) {
          ppiVar17 = (int **)PyObject_Format(ppiVar17,local_68);
          FUN_6bce4790(local_88);
          FUN_6bce47c0();
          iVar3 = opc_dict;
          if (ppiVar17 == (int **)0x0) goto LAB_6bce8b44;
        }
        *(int ***)ppiVar16 = ppiVar17;
        local_80 = local_78;
        ppiVar16_m = local_78;
        puVar15 = local_84;
        goto LAB_6bce5c00;
      case (int **)0x96:
        goto opcode_switch_caseD_96;
      case (int **)0x97:
        piVar7_m = ppiVar16_m[-1];
        local_80 = ppiVar16_m + -1;
        local_88 = (int **)PySet_Add(local_80[(int)oparg_var14 * 0x3fffffff],piVar7_m);
LAB_6bce6f11:
        ppiVar16_m = ppiVar16_m + -1;
        *piVar7_m = *piVar7_m + -1;
        ppiVar17 = local_88;
        if (*piVar7_m == 0) {
          (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
          ppiVar17 = local_88;
        }
LAB_6bce6f2f:
        ppiVar16 = ppiVar16_m;
        iVar3 = opc_dict;
        if (ppiVar17 != (int **)0x0) goto LAB_6bce8b44;
        puVar15 = local_84;
        if ((char)*local_84 == -0x6a) {
          oparg_var14 = (int **)(uint)(*local_84 >> 8);
opcode_switch_caseD_96:
          puVar15 = (ushort *)((int)local_6c + ((uint)oparg_var14 & 0xfffffffe));
        }
        goto LAB_6bce5c00;
      case (int **)0x98:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16_m = ppiVar16_m + -2;
        local_78 = (int **)*ppiVar16_m;
        local_80 = ppiVar16_m;
        ppiVar17 = (int **)PyDict_SetItem(ppiVar16_m[(int)oparg_var14 * 0x3fffffff],local_78,local_88);
        FUN_6bce4790(local_88);
        FUN_6bce4790(local_78);
        goto LAB_6bce6f2f;
      case (int **)0x99:
        local_88 = (int **)PySet_New(0);
        local_68 = (int **)0x0;
        iVar3 = opc_dict;
        if (local_88 == (int **)0x0) goto LAB_6bce8b44;
        local_78 = oparg;
        ppiVar16 = local_68;
        if (0 < (int)oparg) {
          ppiVar16 = (int **)0x0;
          opcode = ppiVar16_m + (int)oparg * 0x3fffffff;
          do {
            piVar7_m = *opcode;
            if (ppiVar16 == (int **)0x0) {
              ppiVar16 = (int **)PySet_Add(local_88,piVar7_m);
            }
            FUN_6bce4790(piVar7_m);
            local_78 = (int **)((int)local_78 + -1);
            opcode = opcode + 1;
            ppiVar16_m = local_80;
            puVar15 = local_84;
          } while (0 < (int)local_78);
        }
        local_68 = ppiVar16;
        ppiVar16 = ppiVar16_m + (int)oparg * 0x3fffffff;
        if (local_68 != (int **)0x0) {
          FUN_6bce4790(local_88);
          iVar3 = opc_dict;
          goto LAB_6bce8b44;
        }
        *(int ***)ppiVar16 = local_88;
        ppiVar16_m = ppiVar16 + 1;
        local_80 = ppiVar16 + 1;
        goto LAB_6bce5c00;
      case (int **)0x9a:
        ppiVar17 = (int **)PyList_New(oparg_var14);
        iVar3 = opc_dict;
        if (ppiVar17 == (int **)0x0) goto LAB_6bce8b44;
        iVar3 = (int)oparg + -1;
        if (-1 < iVar3) goto LAB_6bce7db3;
        goto LAB_6bce7612;
      case (int **)0x9b:
        oparg = *(int ***)(local_60 + 0xc + (int)oparg_var14 * 4);
        iVar4 = *(int *)(opc_dict + 0x1c);
        if (iVar4 == 0) {
          _PyErr_Format(local_7c,PyExc_SystemError,"no locals when loading %R",oparg);
          goto LAB_6bce8b44;
        }
        if (*(undefined **)(iVar4 + 4) == &PyDict_Type) {
          piVar7_m = (int *)PyDict_GetItemWithError();
          if (piVar7_m != (int *)0x0) {
            FUN_6bce4780();
            *ppiVar16_m = piVar7_m;
            ppiVar16_m = ppiVar16_m + 1;
            puVar15 = local_84;
            local_80 = ppiVar16_m;
            goto LAB_6bce5c00;
          }
          iVar4 = FUN_6bce4930();
          iVar3 = opc_dict;
          if (iVar4 != 0) goto LAB_6bce8b44;
        }
        else {
          ppiVar17 = (int **)PyObject_GetItem(iVar4);
          iVar4 = local_7c;
          if (ppiVar17 != (int **)0x0) goto LAB_6bce7612;
          iVar13 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
          iVar3 = opc_dict;
          if (iVar13 == 0) goto LAB_6bce8b44;
          _PyErr_Clear(iVar4);
        }
        piVar7_m = (int *)PyDict_GetItemWithError(*(undefined4 *)(opc_dict + 0x18),oparg);
        if (piVar7_m != (int *)0x0) {
          FUN_6bce4780();
          *ppiVar16_m = piVar7_m;
          ppiVar16_m = ppiVar16_m + 1;
          puVar15 = local_84;
          local_80 = ppiVar16_m;
          goto LAB_6bce5c00;
        }
        iVar4 = FUN_6bce4930();
        iVar3 = opc_dict;
        if (iVar4 != 0) goto LAB_6bce8b44;
        if (*(undefined **)(*(int *)(opc_dict + 0x14) + 4) == &PyDict_Type) {
          piVar7_m = (int *)PyDict_GetItemWithError();
          if (piVar7_m != (int *)0x0) {
            FUN_6bce4780();
            *ppiVar16_m = piVar7_m;
            ppiVar16_m = ppiVar16_m + 1;
            puVar15 = local_84;
            local_80 = ppiVar16_m;
            goto LAB_6bce5c00;
          }
          iVar4 = FUN_6bce4930();
          iVar3 = opc_dict;
          if (iVar4 != 0) goto LAB_6bce8b44;
        }
        else {
          piVar7_m = (int *)PyObject_GetItem(*(int *)(opc_dict + 0x14),oparg);
          if (piVar7_m != (int *)0x0) {
            *ppiVar16_m = piVar7_m;
            ppiVar16_m = ppiVar16_m + 1;
            puVar15 = local_84;
            local_80 = ppiVar16_m;
            goto LAB_6bce5c00;
          }
          iVar4 = _PyErr_ExceptionMatches(local_7c,PyExc_KeyError);
          iVar3 = opc_dict;
          if (iVar4 == 0) goto LAB_6bce8b44;
        }
        FUN_6bcec430("name \'%.200s\' is not defined",oparg);
        iVar3 = opc_dict;
        goto LAB_6bce8b44;
      case (int **)0x9c:
        local_88 = (int **)ppiVar16_m[-1];
        ppiVar16_m = ppiVar16_m + -1;
        local_80 = ppiVar16_m;
        ppiVar17 = (int **)PyDict_SetItem(*(undefined4 *)(opc_dict + 0x18),
                                          *(undefined4 *)(local_60 + 0xc + (int)oparg_var14 * 4),
                                          local_88);
        break;
      case (int **)0x9d:
        opcode = (int **)PyDict_New();
        iVar3 = opc_dict;
        if (opcode == (int **)0x0) goto LAB_6bce8b44;
        local_88 = oparg;
        if ((int)oparg < 1) goto LAB_6bce8317;
        ppiVar17 = ppiVar16_m + (int)oparg * 0x3fffffff;
        goto LAB_6bce82e1;
      case (int **)0x9e:
        piVar7_m = ppiVar16_m[-1];
        local_88 = ppiVar16_m + -1;
        if (piVar7_m == &_Py_TrueStruct) {
LAB_6bce625c:
          local_88 = ppiVar16_m + -1;
          local_80 = local_88;
LAB_6bce6262:
          ppiVar17 = local_80;
          FUN_6bce4790(piVar7_m);
          puVar15 = local_84;
          goto LAB_6bce5d85;
        }
        if (piVar7_m == &_Py_FalseStruct) {
          puVar15 = (ushort *)((int)local_6c + ((uint)oparg_var14 & 0xfffffffe));
          goto LAB_6bce5d85;
        }
        oparg_var14 = (int **)PyObject_IsTrue(piVar7_m);
        ppiVar16_m = local_88;
        if (0 < (int)oparg_var14) {
          local_80 = local_88;
          FUN_6bce4790(piVar7_m);
          puVar15 = local_84;
          goto LAB_6bce5c00;
        }
LAB_6bce67ef:
        ppiVar16 = ppiVar17;
        iVar3 = opc_dict;
        if (oparg_var14 != (int **)0x0) goto LAB_6bce8b44;
        ppiVar16_m = ppiVar17;
        puVar15 = (ushort *)((int)local_6c + ((uint)oparg & 0xfffffffe));
        goto LAB_6bce5c00;
      case (int **)0xa0:
        piVar7_m = ppiVar16_m[-1];
        PyFrame_BlockSetup(opc_dict,0x5d,
                           (int **)((int)oparg_var14 + ((int)((int)puVar15 - (int)local_6c) >> 1) * 2),
                           (int)ppiVar16_m + (-4 - *(int *)(opc_dict + 0x20)) >> 2);
        ppiVar16_m[-1] = piVar7_m;
        local_80 = local_88;
        ppiVar16_m = local_88;
        puVar15 = local_84;
        goto LAB_6bce5c00;
      case (int **)0xa1:
        piVar7_m = *(int **)(local_50 + (int)oparg_var14 * 4);
        FUN_6bce4780();
        *ppiVar16_m = piVar7_m;
        ppiVar16_m = ppiVar16_m + 1;
        puVar15 = local_84;
        local_80 = ppiVar16_m;
        goto LAB_6bce5c00;
      case (int **)0xa2:
        goto opcode_switch_caseD_a2;
      case (int **)0xa3:
        piVar7_m = (int *)PyLong_FromLong((uint)((int)puVar15 - (int)local_6c) & 0xfffffffe);
        iVar3 = opc_dict;
        if (piVar7_m == (int *)0x0) goto LAB_6bce8b44;
        *ppiVar16_m = piVar7_m;
        ppiVar17 = ppiVar16_m + 1;
        local_80 = ppiVar17;
        goto LAB_6bce5d7e;
      }
      FUN_6bce4790(local_88);
      puVar15 = local_84;
joined_r0x6bce767b:
      ppiVar16 = ppiVar16_m;
      iVar3 = opc_dict;
      if (ppiVar17 == (int **)0x0) goto LAB_6bce5c00;
      goto LAB_6bce8b44;
    }
  }
LAB_6bce9438:
  if (_Py_CheckRecursionLimit < 0xc9) {
    iVar4 = (_Py_CheckRecursionLimit >> 2) * 3;
  }
  else {
    iVar4 = _Py_CheckRecursionLimit + -0x32;
  }
  iVar13 = FUN_6bbbb560();
  *(int *)(iVar13 + 0x10) = *(int *)(iVar13 + 0x10) + -1;
  if (*(int *)(iVar13 + 0x10) < iVar4) {
    iVar4 = FUN_6bbbb560();
    *(undefined *)(iVar4 + 0x14) = 0;
  }
  *(undefined *)(opc_dict + 0x40) = 0;
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(opc_dict + 0xc);
  _Py_CheckFunctionResult(0,local_64,"PyEval_EvalFrameEx");
  FUN_6bd5f96c();
  return;
opcode_switch_caseD_a2:
  opcode = (int **)0x0;
  if (oparg_var14 != (int **)0x0) {
    opcode = (int **)ppiVar16_m[-1];
    ppiVar16_m = ppiVar16_m + -1;
  }
  ppiVar16 = (int **)ppiVar16_m[-1];
  ppiVar17 = ppiVar16_m + -1;
  local_80 = ppiVar17;
  if (ppiVar16 != (int **)0x0) {
    piVar7_m = (int *)((int)*ppiVar16 + -1);
    *ppiVar16 = piVar7_m;
    if (ppiVar16[1] == (int *)&PyLong_Type) {
      pcVar10 = pcRam6becb140;
      if (piVar7_m == (int *)0x0) {
LAB_6bce7583:
        (*pcVar10)(ppiVar16);
      }
    }
    else {
      if (piVar7_m == (int *)0x0) {
        (*(code *)ppiVar16[1][6])(ppiVar16);
      }
      piVar7_m = ppiVar16_m[-2];
      *piVar7_m = *piVar7_m + -1;
      if (*piVar7_m == 0) {
        (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
      }
      piVar7_m = ppiVar16_m[-3];
      ppiVar16 = ppiVar16_m + -3;
      *piVar7_m = *piVar7_m + -1;
      if (*piVar7_m == 0) {
        (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
      }
      iVar3 = opc_dict;
      piVar7_m = (int *)PyFrame_BlockPop(opc_dict);
      if (*piVar7_m != 0x101) {
        _PyErr_SetString(local_7c,PyExc_SystemError,"popped block is not an except handler");
        if ((opcode != (int **)0x0) && (*opcode = (int *)((int)*opcode + -1), *opcode == (int *)0x0)
           ) {
          (*(code *)opcode[1][6])(opcode);
        }
        goto LAB_6bce8b44;
      }
      ppiVar16 = *(int ***)(local_7c + 0x50);
      local_88 = (int **)ppiVar16[2];
      piVar7_m = *ppiVar16;
      piVar9 = ppiVar16[1];
      *ppiVar16 = ppiVar16_m[-4];
      ppiVar17 = ppiVar16_m + -6;
      ppiVar16[1] = ppiVar16_m[-5];
      ppiVar16[2] = *ppiVar17;
      local_80 = ppiVar17;
      if ((piVar7_m != (int *)0x0) && (*piVar7_m = *piVar7_m + -1, *piVar7_m == 0)) {
        (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
      }
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
        (**(code **)(piVar9[1] + 0x18))(piVar9);
      }
      if ((local_88 != (int **)0x0) &&
         (*local_88 = (int *)((int)*local_88 + -1), *local_88 == (int *)0x0)) {
        pcVar10 = (code *)local_88[1][6];
        ppiVar16 = local_88;
        goto LAB_6bce7583;
      }
    }
  }
  ppiVar16_m = ppiVar17;
  puVar15 = local_84;
  if (oparg != (int **)0x0) {
    *(int ***)ppiVar17 = opcode;
    ppiVar16_m = ppiVar17 + 1;
    local_80 = ppiVar17 + 1;
  }
  goto LAB_6bce5c00;
  while( true ) {
    ppiVar17 = ppiVar17 + 1;
    local_88 = (int **)((int)local_88 + -1);
    puVar15 = local_84;
    if ((int)local_88 < 1) break;
LAB_6bce82e1:
    local_78 = (int **)*ppiVar17;
    iVar4 = PyDict_Update(opcode,local_78);
    iVar3 = local_7c;
    if (iVar4 < 0) {
      iVar4 = _PyErr_ExceptionMatches(local_7c,PyExc_AttributeError);
      if (iVar4 != 0) {
        _PyErr_Format(iVar3,PyExc_TypeError,"\'%.200s\' object is not a mapping",local_78[1][3]);
      }
      FUN_6bce4790(opcode);
      iVar3 = opc_dict;
      goto LAB_6bce8b44;
    }
  }
LAB_6bce8317:
  if (oparg != (int **)0x0) {
    do {
      ppiVar16 = ppiVar16_m;
      oparg = (int **)((int)oparg + -1);
      FUN_6bce4790(ppiVar16[-1]);
      ppiVar16_m = ppiVar16 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar16 + -1) = opcode;
    ppiVar16_m = ppiVar16;
    local_80 = ppiVar16;
    goto LAB_6bce5c00;
  }
LAB_6bce7ffb:
  *(int ***)ppiVar16_m = opcode;
  ppiVar16_m = ppiVar16_m + 1;
  local_80 = ppiVar16_m;
  goto LAB_6bce5c00;
LAB_6bce7db3:
  do {
    local_80 = ppiVar16_m;
    ppiVar16_m = local_80 + -1;
    *(int **)(ppiVar17[3] + iVar3) = *ppiVar16_m;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  *(int ***)ppiVar16_m = ppiVar17;
  ppiVar16_m = local_80;
  puVar15 = local_84;
  goto LAB_6bce5c00;
  while( true ) {
    ppiVar17 = ppiVar17 + 2;
    local_88 = (int **)((int)local_88 + -1);
    puVar15 = local_84;
    if ((int)local_88 < 1) break;
LAB_6bce8040:
    iVar3 = PyDict_SetItem(opcode,*ppiVar17,ppiVar17[1]);
    if (iVar3 != 0) {
      FUN_6bce4790(opcode);
      iVar3 = opc_dict;
      goto LAB_6bce8b44;
    }
  }
LAB_6bce8074:
  if (oparg != (int **)0x0) {
    do {
      ppiVar16 = ppiVar16_m;
      oparg = (int **)((int)oparg + -1);
      FUN_6bce4790(ppiVar16[-1]);
      ppiVar16_m = ppiVar16 + -2;
      FUN_6bce4790(*ppiVar16_m);
    } while (oparg != (int **)0x0);
    *(int ***)ppiVar16_m = opcode;
    ppiVar16_m = ppiVar16 + -1;
    local_80 = ppiVar16 + -1;
    goto LAB_6bce5c00;
  }
  goto LAB_6bce7ffb;
opcode_switch_caseD_6d:
  uVar2 = *puVar15;
  oparg_var14 = (int **)((int)oparg_var14 << 8 | (uint)(uVar2 >> 8));
  goto LAB_6bce5e10;
  while( true ) {
    ppiVar16_m = ppiVar16_m + 1;
    local_88 = (int **)((int)local_88 + -1);
    local_78 = local_78 + 1;
    puVar15 = local_84;
    if ((int)local_88 < 1) break;
LAB_6bce8220:
    iVar3 = PyDict_SetItem(opcode,*local_78,*ppiVar16_m);
    if (iVar3 != 0) {
      FUN_6bce4790(opcode);
      iVar3 = opc_dict;
      goto LAB_6bce8b44;
    }
  }
LAB_6bce8258:
  ppiVar16_m = local_68;
  FUN_6bce4790(*local_68);
  if (oparg != (int **)0x0) {
    do {
      ppiVar16 = ppiVar16_m;
      oparg = (int **)((int)oparg + -1);
      FUN_6bce4790(ppiVar16[-1]);
      ppiVar16_m = ppiVar16 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar16 + -1) = opcode;
    ppiVar16_m = ppiVar16;
    local_80 = ppiVar16;
    goto LAB_6bce5c00;
  }
  goto LAB_6bce7ffb;
  while( true ) {
    ppiVar17 = ppiVar17 + 1;
    local_88 = (int **)((int)local_88 + -1);
    puVar15 = local_84;
    if ((int)local_88 < 1) break;
LAB_6bce7fa3:
    iVar3 = _PySet_Update(opcode,*ppiVar17);
    if (iVar3 < 0) {
      FUN_6bce4790(opcode);
      iVar3 = opc_dict;
      goto LAB_6bce8b44;
    }
  }
joined_r0x6bce7fd4:
  while (oparg != (int **)0x0) {
    ppiVar16 = ppiVar16_m + -1;
    ppiVar16_m = ppiVar16_m + -1;
    oparg = (int **)((int)oparg + -1);
    FUN_6bce4790(*ppiVar16);
  }
  goto LAB_6bce7ffb;
  while( true ) {
    FUN_6bce4790(iVar3);
    local_68 = (int **)((int)local_68 + -1);
    local_78 = local_78 + 1;
    if ((int)local_68 < 1) break;
LAB_6bce7e08:
    iVar3 = _PyList_Extend(local_80,*local_78);
    if (iVar3 == 0) {
      if ((opcode == (int **)0x8f) &&
         (iVar3 = _PyErr_ExceptionMatches(local_7c,PyExc_TypeError), iVar3 != 0)) {
        FUN_6bcec210(ppiVar16_m[(int)local_68 * 0x3fffffff]);
      }
      FUN_6bce4790(local_80);
      iVar3 = opc_dict;
      goto LAB_6bce8b44;
    }
  }
LAB_6bce7e4a:
  ppiVar17 = local_80;
  if (opcode != (int **)0x65) {
    ppiVar17 = (int **)PyList_AsTuple(local_80);
    FUN_6bce4790(local_80);
    iVar3 = opc_dict;
    if (ppiVar17 == (int **)0x0) {
LAB_6bce8b44:
      iVar4 = FUN_6bce4930();
      if (iVar4 == 0) {
        _PyErr_SetString(local_7c,PyExc_SystemError,"error return without exception set");
      }
      PyTraceBack_Here(iVar3);
      if (*(int *)(local_7c + 0x28) != 0) {
        FUN_6bceabe0(local_7c,iVar3);
      }
LAB_6bce8b90:
      do {
        if (*(int *)(opc_dict + 0x3c) < 1) goto LAB_6bce9376;
        iVar3 = *(int *)(opc_dict + 0x3c) + -1;
        *(int *)(opc_dict + 0x3c) = iVar3;
        iVar3 = opc_dict + iVar3 * 0xc;
        iVar4 = *(int *)(opc_dict + 0x20);
        iVar13 = (int)((int)ppiVar16 - iVar4) >> 2;
        if (*(int *)(iVar3 + 0x44) == 0x101) {
          if (*(int *)(iVar3 + 0x4c) + 3 < iVar13) {
            do {
              ppiVar16 = ppiVar16 + -1;
              FUN_6bce47c0();
            } while (*(int *)(iVar3 + 0x4c) + 3 <
                     (int)((int)ppiVar16 - *(int *)(opc_dict + 0x20)) >> 2);
          }
          ppiVar17 = *(int ***)(local_7c + 0x50);
          local_88 = (int **)ppiVar17[2];
          *ppiVar17 = ppiVar16[-1];
          ppiVar16_m = ppiVar16 + -2;
          ppiVar16 = ppiVar16 + -3;
          ppiVar17[1] = *ppiVar16_m;
          ppiVar17[2] = *ppiVar16;
          FUN_6bce47c0();
          FUN_6bce47c0();
          FUN_6bce47c0();
          goto LAB_6bce8b90;
        }
        if (*(int *)(iVar3 + 0x4c) < iVar13) {
          do {
            ppiVar16 = ppiVar16 + -1;
            FUN_6bce47c0();
            iVar4 = *(int *)(opc_dict + 0x20);
          } while (*(int *)(iVar3 + 0x4c) < (int)((int)ppiVar16 - iVar4) >> 2);
        }
      } while (*(int *)(iVar3 + 0x44) != 0x5d);
      local_78 = *(int ***)(iVar3 + 0x48);
      ppiVar16_m = *(int ***)(local_7c + 0x50);
      PyFrame_BlockSetup(opc_dict,0x101,0xffffffff,(int)((int)ppiVar16 - iVar4) >> 2);
      local_88 = ppiVar16 + 3;
      *ppiVar16 = ppiVar16_m[2];
      ppiVar16[1] = ppiVar16_m[1];
      piVar7_m = *ppiVar16_m;
      if (piVar7_m == (int *)0x0) {
        FUN_6bce4780();
        piVar7_m = &_Py_NoneStruct;
      }
      iVar3 = local_7c;
      ppiVar16[2] = piVar7_m;
      _PyErr_Fetch(local_7c,&local_44,&local_54,&local_58);
      _PyErr_NormalizeException(iVar3,&local_44,&local_54,&local_58);
      piVar7_m = local_58;
      if (local_58 == (int *)0x0) {
        piVar7_m = &_Py_NoneStruct;
      }
      PyException_SetTraceback(local_54,piVar7_m);
      FUN_6bce4780();
      *ppiVar16_m = local_44;
      FUN_6bce4780();
      ppiVar16_m[1] = local_54;
      ppiVar16_m[2] = local_58;
      if (local_58 == (int *)0x0) {
        local_58 = &_Py_NoneStruct;
      }
      FUN_6bce4780();
      *local_88 = local_58;
      local_88[1] = local_54;
      local_88[2] = local_44;
      ppiVar16_m = local_88 + 3;
      puVar15 = (ushort *)((int)local_6c + ((uint)local_78 & 0xfffffffe));
      local_80 = local_88 + 3;
      goto LAB_6bce5c00;
    }
  }
  if (oparg == (int **)0x0) {
LAB_6bce7612:
    *(int ***)ppiVar16_m = ppiVar17;
    ppiVar16_m = ppiVar16_m + 1;
    puVar15 = local_84;
    local_80 = ppiVar16_m;
  }
  else {
    do {
      ppiVar16 = ppiVar16_m;
      oparg = (int **)((int)oparg + -1);
      FUN_6bce4790(ppiVar16[-1]);
      ppiVar16_m = ppiVar16 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar16 + -1) = ppiVar17;
    ppiVar16_m = ppiVar16;
    puVar15 = local_84;
    local_80 = ppiVar16;
  }
  goto LAB_6bce5c00;
joined_r0x6bce7d11:
  while (oparg = (int **)((int)ppiVar17 + -1), -1 < (int)oparg) {
    ppiVar16 = ppiVar16_m + -1;
    ppiVar16_m = ppiVar16_m + -1;
    FUN_6bce4790(*ppiVar16);
    ppiVar17 = oparg;
  }
  *(int ***)ppiVar16_m = opcode;
  ppiVar16_m = ppiVar16_m + 1;
  puVar15 = local_84;
  local_80 = ppiVar16_m;
  goto LAB_6bce5c00;
  while( true ) {
    ppiVar17 = ppiVar17 + 1;
    local_88 = (int **)((int)local_88 + -1);
    puVar15 = local_84;
    if ((int)local_88 < 1) break;
LAB_6bce8381:
    local_78 = (int **)*ppiVar17;
    iVar3 = _PyDict_MergeEx(opcode,local_78,2);
    if (iVar3 < 0) {
      FUN_6bce4790(opcode);
      FUN_6bcec2a0(local_78);
      iVar3 = opc_dict;
      goto LAB_6bce8b44;
    }
  }
LAB_6bce83b9:
  if (oparg != (int **)0x0) {
    do {
      ppiVar16 = ppiVar16_m;
      oparg = (int **)((int)oparg + -1);
      FUN_6bce4790(ppiVar16[-1]);
      ppiVar16_m = ppiVar16 + -1;
    } while (oparg != (int **)0x0);
    *(int ***)(ppiVar16 + -1) = opcode;
    ppiVar16_m = ppiVar16;
    local_80 = ppiVar16;
    goto LAB_6bce5c00;
  }
  goto LAB_6bce7ffb;
joined_r0x6bce6940:
  while (ppiVar16_m = ppiVar16, oparg_var14 != (int **)0x0) {
    piVar7_m = local_68[(int)oparg_var14 + 2];
    oparg = (int **)((int)oparg_var14 + -1);
    FUN_6bce4780();
    *ppiVar16 = piVar7_m;
    ppiVar16 = ppiVar16 + 1;
    oparg_var14 = oparg;
  }
LAB_6bce85d4:
  local_80 = ppiVar16_m;
  ppiVar16_m = local_80;
  FUN_6bce4790(local_68);
  puVar15 = local_84;
  goto LAB_6bce5c00;
opcode_switch_caseD_5:
  piVar7_m = ppiVar16_m[-1];
  local_88 = (int **)FUN_6bc57fd0();
  if (local_88 == (int **)0x0) {
    FUN_6bcec500((uint)local_84[-2] & 0xff);
  }
  *piVar7_m = *piVar7_m + -1;
  if (*piVar7_m == 0) {
    (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
  }
  ppiVar17 = local_88;
  bVar18 = local_88 == (int **)0x0;
  ppiVar16 = local_88;
  if (!bVar18) {
    ppiVar16 = ppiVar17;
    if ((local_88[1] == (int *)&PyCoro_Type) &&
       (piVar7_m = (int *)FUN_6bc574b0(), piVar7_m != (int *)0x0)) {
      *piVar7_m = *piVar7_m + -1;
      if (*piVar7_m == 0) {
        (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
      }
      ppiVar16 = (int **)0x0;
      *ppiVar17 = (int *)((int)*ppiVar17 + -1);
      if (*ppiVar17 == (int *)0x0) {
        (*(code *)ppiVar17[1][6])(ppiVar17);
      }
      _PyErr_SetString(local_7c,PyExc_RuntimeError,"coroutine is being awaited already");
    }
LAB_6bce652f:
    bVar18 = ppiVar16 == (int **)0x0;
  }
  *(int ***)(ppiVar16_m + -1) = ppiVar16;
  ppiVar16 = ppiVar16_m;
  iVar3 = opc_dict;
  puVar15 = local_84;
  if (bVar18) goto LAB_6bce8b44;
LAB_6bce653e:
  if ((char)*puVar15 != 'a') goto LAB_6bce5c00;
  oparg_var14 = (int **)(uint)(*puVar15 >> 8);
  puVar15 = puVar15 + 1;
opcode_switch_caseD_61:
  piVar7_m = *(int **)(local_24 + 0xc + (int)oparg_var14 * 4);
  *piVar7_m = *piVar7_m + 1;
  *ppiVar16_m = piVar7_m;
  ppiVar17 = ppiVar16_m + 1;
  local_80 = ppiVar16_m + 1;
  goto LAB_6bce5d85;
opcode_switch_caseD_1:
  piVar7_m = ppiVar16_m[-2];
  local_80 = ppiVar16_m + -1;
  local_88 = (int **)*local_80;
  local_78 = (int **)FUN_6bc1f4c0(0x60,0x2c,&DAT_6be8b72c);
LAB_6bce6e23:
  *piVar7_m = *piVar7_m + -1;
  if (*piVar7_m == 0) {
    (**(code **)(piVar7_m[1] + 0x18))(piVar7_m);
  }piVar7 = ppiVar16[-1];
  *local_88 = (int *)((int)*local_88 + -1);
  ppiVar16 = local_78;
  ppiVar17 = ppiVar16_m + -1;
  if (*local_88 == (int *)0x0) {
    (*(code *)local_88[1][6])(local_88);
    ppiVar16 = local_78;
  }
LAB_6bce6d7c:
  ppiVar16_m = ppiVar17;
  bVar18 = ppiVar16 == (int **)0x0;
  *(int ***)(ppiVar16_m + -1) = ppiVar16;
LAB_6bce6d81:
  ppiVar16 = ppiVar16_m;
  puVar15 = local_84;
  iVar3 = opc_dict;
  if (!bVar18) goto LAB_6bce5c00;
  goto LAB_6bce8b44;
LAB_6bce9376:
  ppiVar16_m = (int **)((int)ppiVar16 - *(int *)(opc_dict + 0x20));
  while (((uint)ppiVar16_m & 0xfffffffc) != 0) {
    ppiVar16 = ppiVar16 + -1;
    FUN_6bce47c0();
    ppiVar16_m = (int **)((int)ppiVar16 - *(int *)(opc_dict + 0x20));
  }
LAB_6bce93a1:
  iVar3 = local_7c;
  if (*(int *)(local_7c + 0x20) != 0) {
    if (((*(int *)(local_7c + 0x28) != 0) &&
        (iVar4 = FUN_6bcead30(local_7c,opc_dict,3,local_64), piVar7_m = local_64, iVar4 != 0)) &&
       (local_64 != (int *)0x0)) {
      local_64 = (int *)0x0;
      FUN_6bce4790(piVar7_m);
    }
    piVar7_m = local_64;
    if (((*(int *)(iVar3 + 0x24) != 0) &&
        (iVar4 = FUN_6bcead30(iVar3,opc_dict,3,local_64), iVar4 != 0)) && (piVar7_m != (int *)0x0)) {
      local_64 = (int *)0x0;
      FUN_6bce4790(piVar7_m);
    }
  }
  goto LAB_6bce9438;
}