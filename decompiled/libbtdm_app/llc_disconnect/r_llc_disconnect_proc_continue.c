/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_disconnect.o -> r_llc_disconnect_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_disconnect_proc_continue(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == 0) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar2 == 0) {
      (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,3,*(code **)(_r_ip_funcs_p + 0x664));
      *(undefined1 *)(iVar5 + 0x47) = *(undefined1 *)(iVar1 + 9);
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      *(undefined1 *)(iVar5 + 0x46) = *(undefined1 *)(iVar1 + 9);
      llc_ll_terminate_ind_pdu_send(param_1,*(undefined1 *)(iVar1 + 8));
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
      (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
                    /* WARNING: Could not recover jumptable at 0x00010180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
      return;
    }
    if (iVar2 == 1) {
      (**(code **)(_r_ip_funcs_p + 0x55c))
                (param_1,*(undefined1 *)(iVar1 + 9),1,*(code **)(_r_ip_funcs_p + 0x55c));
    }
    else {
      pcVar4 = *(code **)(_r_plf_funcs_p + 0xc);
      uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
      (*pcVar4)(param_1,uVar3,"llc_disconnect.c",0xc0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000101ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
  return;
}

