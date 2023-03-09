/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm.o -> r_llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_update_duplicate_scan_exceptional_list(int param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  size_t sVar6;
  undefined4 uVar7;
  
  if (param_1 != 1) {
    if (param_1 == 0) {
      if (param_3 == (void *)0x0) {
        return 0x12;
      }
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
      if (param_2 == 0) {
        piVar4 = (int *)(iVar3 + 0x2c);
        sVar6 = 6;
      }
      else {
        if (param_2 != 1) {
          if (param_2 == 2) {
            uVar5 = *(uint *)(iVar3 + 0x28) | 4;
          }
          else if (param_2 == 3) {
            uVar5 = *(uint *)(iVar3 + 0x28) | 8;
          }
          else {
            if (param_2 != 4) {
              return 0x12;
            }
            uVar5 = *(uint *)(iVar3 + 0x28) | 0x10;
          }
          goto _L99;
        }
        piVar4 = (int *)(iVar3 + 0x34);
        sVar6 = 4;
      }
      if (piVar4 == (int *)0x0) {
        return 0x12;
      }
      for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        iVar2 = memcmp(piVar4 + 1,param_3,sVar6);
        if (iVar2 == 0) goto _L100;
      }
      iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))
                        (0xc,0,*(code **)(_r_modules_funcs_p + 0x120));
      if (iVar2 == 0) {
        return 7;
      }
      if (param_2 == 0) {
        memcpy((void *)(iVar2 + 4),param_3,6);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (iVar3 + 0x2c,iVar2,*(code **)(_r_modules_funcs_p + 0x4c));
        uVar5 = *(uint *)(iVar3 + 0x28) | 1;
_L99:
        *(uint *)(iVar3 + 0x28) = uVar5;
        return 0;
      }
      if (param_2 == 1) {
        memcpy((void *)(iVar2 + 4),param_3,4);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (iVar3 + 0x34,iVar2,*(code **)(_r_modules_funcs_p + 0x4c));
        uVar5 = *(uint *)(iVar3 + 0x28) | 2;
        goto _L99;
      }
    }
    else {
      if (param_1 != 2) {
        return 0xc;
      }
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
      *(uint *)(iVar3 + 0x28) = ~param_2 & *(uint *)(iVar3 + 0x28);
      if ((param_2 & 1) != 0) {
        llm_util_flush_list(iVar3 + 0x2c);
      }
      if ((param_2 & 2) != 0) {
        llm_util_flush_list(iVar3 + 0x34);
      }
    }
    goto _L100;
  }
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  uVar7 = 0x12;
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  switch(param_2) {
  case 0:
    piVar4 = (int *)(iVar3 + 0x2c);
    sVar6 = 6;
    goto _L70;
  case 1:
    piVar4 = (int *)(iVar3 + 0x34);
    sVar6 = 4;
_L70:
    if (piVar4 == (int *)0x0) {
      return 0x12;
    }
    for (piVar1 = (int *)*piVar4; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      iVar2 = memcmp(piVar1 + 1,param_3,sVar6);
      if (iVar2 == 0) {
        (**(code **)(_r_modules_funcs_p + 0x1c))
                  (piVar4,piVar1,*(code **)(_r_modules_funcs_p + 0x1c));
        (**(code **)(_r_modules_funcs_p + 0x110))(piVar1,*(code **)(_r_modules_funcs_p + 0x110));
        break;
      }
    }
    if (*(int *)(iVar3 + 0x2c) == 0) {
      *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0xfffffffe;
    }
    if (*(int *)(iVar3 + 0x34) == 0) {
      uVar5 = *(uint *)(iVar3 + 0x28) & 0xfffffffd;
      break;
    }
    goto _L100;
  case 2:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xfffffffb;
    break;
  case 3:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xfffffff7;
    break;
  case 4:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xffffffef;
    break;
  default:
    goto _L95;
  }
  *(uint *)(iVar3 + 0x28) = uVar5;
_L100:
  uVar7 = 0;
_L95:
  return uVar7;
}

