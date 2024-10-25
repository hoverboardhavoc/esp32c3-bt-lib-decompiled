/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_disconnect.o -> r_llc_disconnect_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_disconnect_proc_continue(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  if (param_2 == 0) {
    iVar5 = *(int *)(&llc_env + param_1 * 4);
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar3 == 0) {
      (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,3,*(code **)(_r_ip_funcs_p + 0x664));
      *(undefined1 *)(iVar5 + 0x47) = *(undefined1 *)(iVar2 + 9);
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      *(undefined1 *)(iVar5 + 0x46) = *(undefined1 *)(iVar2 + 9);
      llc_ll_terminate_ind_pdu_send(param_1,*(undefined1 *)(iVar2 + 8));
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
      (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
                    /* WARNING: Could not recover jumptable at 0x0001016c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1);
      return;
    }
    if (iVar3 == 1) {
      (**(code **)(_r_ip_funcs_p + 0x55c))
                (param_1,*(undefined1 *)(iVar2 + 9),1,*(code **)(_r_ip_funcs_p + 0x55c));
    }
    else {
      pcVar1 = *(code **)(_r_plf_funcs_p + 0xc);
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
      (*pcVar1)(param_1,uVar4,"llc_disconnect.c",0xc0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001019a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0);
  return;
}

