/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_ver_exch.o -> r_llc_ver_exch_loc_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_ver_exch_loc_proc_continue(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar3 == 0) {
    if ((*(ushort *)(iVar1 + 0x42) & 4) == 0) {
      llc_llcp_version_ind_pdu_send(param_1);
      *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) | 8;
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
                    /* WARNING: Could not recover jumptable at 0x00010160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1);
      return;
    }
  }
  else if (iVar3 == 1) {
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
  }
  else {
    param_2 = 0x1f;
    pcVar5 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
    (*pcVar5)(param_1,uVar4,"llc_ver_exch.c",0xbf);
  }
  if (*(char *)(iVar2 + 8) != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x624))
              (param_1,param_2,iVar1 + 0x38,*(code **)(_r_ip_funcs_p + 0x624));
    *(byte *)(iVar1 + 0x45) = *(byte *)(iVar1 + 0x45) & 0xfd;
  }
                    /* WARNING: Could not recover jumptable at 0x000101b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0);
  return;
}

