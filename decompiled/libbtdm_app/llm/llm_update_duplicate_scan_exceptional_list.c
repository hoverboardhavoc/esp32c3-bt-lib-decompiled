/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
 * Source: libbtdm_app -> llm.o -> llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_update_duplicate_scan_exceptional_list(int param_1,uint param_2,void *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  if (param_1 != 1) {
    if (param_1 == 0) {
      if (param_3 == (void *)0x0) {
        return 0x12;
      }
      piVar1 = le_scan_duplicate_option;
      if (param_2 == 0) {
        sVar4 = 6;
      }
      else {
        if (param_2 != 1) {
          if (param_2 == 2) {
            DAT_00010818 = DAT_00010818 | 4;
            return 0;
          }
          if (param_2 != 3) {
            if (param_2 != 4) {
              return 0x12;
            }
            DAT_00010818 = DAT_00010818 | 0x10;
            return 0;
          }
          DAT_00010818 = DAT_00010818 | 8;
          return 0;
        }
        sVar4 = 4;
      }
      for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        iVar3 = memcmp(piVar1 + 1,param_3,sVar4);
        if (iVar3 == 0) goto _L87;
      }
      iVar3 = (**(code **)(_r_modules_funcs_p + 0x120))
                        (0xc,0,*(code **)(_r_modules_funcs_p + 0x120));
      if (iVar3 == 0) {
        return 7;
      }
      if (param_2 == 0) {
        memcpy((void *)(iVar3 + 4),param_3,6);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (&DAT_0001081c,iVar3,*(code **)(_r_modules_funcs_p + 0x4c));
        DAT_00010818 = DAT_00010818 | 1;
        return 0;
      }
      if (param_2 == 1) {
        memcpy((void *)(iVar3 + 4),param_3,4);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (&DAT_00010824,iVar3,*(code **)(_r_modules_funcs_p + 0x4c));
        DAT_00010818 = DAT_00010818 | 2;
        return 0;
      }
    }
    else {
      if (param_1 != 2) {
        return 0xc;
      }
      DAT_00010818 = ~param_2 & DAT_00010818;
      if ((param_2 & 1) != 0) {
        llm_util_flush_list_part_0(&DAT_0001081c);
      }
      if ((param_2 & 2) != 0) {
        llm_util_flush_list_part_0(&DAT_00010824);
      }
    }
    goto _L87;
  }
  uVar6 = 0x12;
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  switch(param_2) {
  case 0:
    sVar4 = 6;
    puVar5 = &DAT_0001081c;
    goto _L60;
  case 1:
    sVar4 = 4;
    puVar5 = &DAT_00010824;
_L60:
    for (puVar2 = (undefined4 *)*puVar5; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2
        ) {
      iVar3 = memcmp(puVar2 + 1,param_3,sVar4);
      if (iVar3 == 0) {
        (**(code **)(_r_modules_funcs_p + 0x1c))
                  (puVar5,puVar2,*(code **)(_r_modules_funcs_p + 0x1c));
        (**(code **)(_r_modules_funcs_p + 0x110))(puVar2,*(code **)(_r_modules_funcs_p + 0x110));
        break;
      }
    }
    if (DAT_0001081c == 0) {
      DAT_00010818 = DAT_00010818 & 0xfffffffe;
    }
    if (DAT_00010824 == 0) {
      DAT_00010818 = DAT_00010818 & 0xfffffffd;
    }
    break;
  case 2:
    DAT_00010818 = DAT_00010818 & 0xfffffffb;
    break;
  case 3:
    DAT_00010818 = DAT_00010818 & 0xfffffff7;
    break;
  case 4:
    DAT_00010818 = DAT_00010818 & 0xffffffef;
    break;
  default:
    goto _L82;
  }
_L87:
  uVar6 = 0;
_L82:
  return uVar6;
}

