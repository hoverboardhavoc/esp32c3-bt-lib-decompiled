/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
            DAT_000107f4 = DAT_000107f4 | 4;
            return 0;
          }
          if (param_2 != 3) {
            if (param_2 != 4) {
              return 0x12;
            }
            DAT_000107f4 = DAT_000107f4 | 0x10;
            return 0;
          }
          DAT_000107f4 = DAT_000107f4 | 8;
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
                  (&DAT_000107f8,iVar3,*(code **)(_r_modules_funcs_p + 0x4c));
        DAT_000107f4 = DAT_000107f4 | 1;
        return 0;
      }
      if (param_2 == 1) {
        memcpy((void *)(iVar3 + 4),param_3,4);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (&DAT_00010800,iVar3,*(code **)(_r_modules_funcs_p + 0x4c));
        DAT_000107f4 = DAT_000107f4 | 2;
        return 0;
      }
    }
    else {
      if (param_1 != 2) {
        return 0xc;
      }
      DAT_000107f4 = ~param_2 & DAT_000107f4;
      if ((param_2 & 1) != 0) {
        llm_util_flush_list_part_0(&DAT_000107f8);
      }
      if ((param_2 & 2) != 0) {
        llm_util_flush_list_part_0(&DAT_00010800);
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
    puVar5 = &DAT_000107f8;
    goto _L60;
  case 1:
    sVar4 = 4;
    puVar5 = &DAT_00010800;
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
    if (DAT_000107f8 == 0) {
      DAT_000107f4 = DAT_000107f4 & 0xfffffffe;
    }
    if (DAT_00010800 == 0) {
      DAT_000107f4 = DAT_000107f4 & 0xfffffffd;
    }
    break;
  case 2:
    DAT_000107f4 = DAT_000107f4 & 0xfffffffb;
    break;
  case 3:
    DAT_000107f4 = DAT_000107f4 & 0xfffffff7;
    break;
  case 4:
    DAT_000107f4 = DAT_000107f4 & 0xffffffef;
    break;
  default:
    goto _L82;
  }
_L87:
  uVar6 = 0;
_L82:
  return uVar6;
}

