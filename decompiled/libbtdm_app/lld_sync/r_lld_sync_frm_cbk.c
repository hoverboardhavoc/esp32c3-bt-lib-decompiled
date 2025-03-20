/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_cbk(undefined4 param_1,uint param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar1 + 0xd) <= param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_2,param_3,"lld_sync.c",0x458,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (param_3 == 1) {
    uVar2 = 1;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x14c);
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x150);
      }
      else {
        if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00011404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(_r_plf_funcs_p + 0xc))(param_2,param_3,"lld_sync.c",0x46e);
          return;
        }
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x154);
      }
                    /* WARNING: Could not recover jumptable at 0x00011454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff);
      return;
    }
    uVar2 = 0;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x14c);
  }
                    /* WARNING: Could not recover jumptable at 0x00011426. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff,param_1,uVar2);
  return;
}

