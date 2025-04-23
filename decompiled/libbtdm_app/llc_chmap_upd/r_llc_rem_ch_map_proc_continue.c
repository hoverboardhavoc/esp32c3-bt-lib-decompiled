/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar3 == param_2) {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
    iVar3 = _r_ip_funcs_p;
    if (iVar4 == 3) {
      uVar1 = *(undefined2 *)(iVar2 + 0xe);
      *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) | 0x10;
      iVar3 = (**(code **)(iVar3 + 0x31c))(param_1,iVar2 + 8,uVar1,*(code **)(iVar3 + 0x31c));
      if (iVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000100e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar2,param_1,4,*(code **)(_r_ip_funcs_p + 0x684));
        return;
      }
    }
    else {
      if (iVar4 != 4) {
        UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
        uVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar2,*(code **)(_r_ip_funcs_p + 0x680));
                    /* WARNING: Could not recover jumptable at 0x000100a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,uVar5,0x10000,0x11d,UNRECOVERED_JUMPTABLE);
        return;
      }
      memcpy((void *)(iVar6 + 8),(void *)(iVar2 + 8),5);
    }
  }
  *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) & 0xffef;
                    /* WARNING: Could not recover jumptable at 0x00010118. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
  return;
}

