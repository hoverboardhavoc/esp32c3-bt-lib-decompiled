/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc.o -> r_llc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_init(int param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  puVar2 = (undefined2 *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar3 = _r_plf_funcs_p;
  if (param_1 == 1) {
    memset(&llc_env,0,0x28);
    *puVar2 = 0;
  }
  else {
    if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001005a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0x164))(1,&TASK_DESC_LLC);
      return;
    }
    if (param_1 == 2) {
      *puVar2 = 0;
      iVar3 = (**(code **)(iVar3 + 0x38))(*(code **)(iVar3 + 0x38));
      for (uVar1 = (int)((*(byte *)(iVar3 + 0xd) - 1) * 0x1000000) >> 0x18; -1 < (char)uVar1;
          uVar1 = uVar1 - 1) {
        if (*(int *)(&llc_env + uVar1 * 4) != 0) {
          (**(code **)(_r_ip_funcs_p + 0x65c))(uVar1 & 0xff,1,*(code **)(_r_ip_funcs_p + 0x65c));
        }
      }
    }
  }
  return;
}

