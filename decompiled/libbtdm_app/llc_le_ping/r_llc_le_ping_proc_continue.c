/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_le_ping.o -> r_llc_le_ping_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_le_ping_proc_continue(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar2 == param_2) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(uVar1,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar2 == 0) {
      llc_ll_ping_req_pdu_send(param_1);
                    /* WARNING: Could not recover jumptable at 0x000101a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1);
      return;
    }
    if (iVar2 != 1) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
      uVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(uVar1,*(code **)(_r_ip_funcs_p + 0x680));
                    /* WARNING: Could not recover jumptable at 0x0001017e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(param_1,uVar1,"llc_le_ping.c",0xf5);
      return;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
                    /* WARNING: Could not recover jumptable at 0x000101d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0);
  return;
}

