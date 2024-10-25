/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_chmap_upd.o -> r_llc_rem_ch_map_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_ch_map_proc_continue(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar3 == param_2) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar3 == 3) {
      uVar1 = *(undefined2 *)(iVar2 + 0xe);
      *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) | 0x10;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x31c))
                        (param_1,iVar2 + 8,uVar1,*(code **)(_r_ip_funcs_p + 0x31c));
      if (iVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000100dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,4);
        return;
      }
    }
    else {
      if (iVar3 != 4) {
        UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
        uVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
                    /* WARNING: Could not recover jumptable at 0x0001009a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,uVar4,"llc_chmap_upd.c",0x11d);
        return;
      }
      memcpy((void *)(iVar5 + 8),(void *)(iVar2 + 8),5);
    }
  }
  *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) & 0xffef;
                    /* WARNING: Could not recover jumptable at 0x00010116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1);
  return;
}

