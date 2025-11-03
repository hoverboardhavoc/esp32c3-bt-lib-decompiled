/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_adv_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_update_hack(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    iVar1 = ke_msg_is_in_queue(0x207);
    if (iVar1 == 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,0,"lld_adv.c",0xde6,*(code **)(_r_plf_funcs_p + 0xc));
    }
  }
  else if (*(char *)(iVar1 + 0x89) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x17c))
              (param_1,param_2,param_3,1,0,*(code **)(_r_ip_funcs_p + 0x17c));
  }
  else {
    if (*(short *)(iVar1 + 0x24) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    }
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    *(short *)(iVar1 + 0x28) = (short)param_2;
    *(short *)(iVar1 + 0x24) = (short)param_3;
    if (param_2 == 0) {
      adv_adv_data_need_to_set[param_1] = 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000162d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

