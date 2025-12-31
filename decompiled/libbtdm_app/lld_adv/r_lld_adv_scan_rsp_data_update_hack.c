/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_scan_rsp_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_update_hack(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    iVar1 = ke_msg_is_in_queue(0x207);
    if (iVar1 == 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,0,"lld_adv.c",0xe0f,*(code **)(_r_plf_funcs_p + 0xc));
    }
  }
  else if (*(char *)(iVar1 + 0x89) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x1d8))
              (param_1,param_2,param_3,1,0,*(code **)(_r_ip_funcs_p + 0x1d8));
  }
  else {
    if (*(short *)(iVar1 + 0x26) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    }
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    *(short *)(iVar1 + 0x2a) = (short)param_2;
    *(short *)(iVar1 + 0x26) = (short)param_3;
    if (param_2 == 0) {
      adv_scan_rsp_data_need_to_set[param_1] = 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000163a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

