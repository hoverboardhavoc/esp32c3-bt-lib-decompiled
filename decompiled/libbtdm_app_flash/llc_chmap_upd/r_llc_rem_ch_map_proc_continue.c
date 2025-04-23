/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> r_llc_rem_ch_map_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_ch_map_proc_continue(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llc_proc_get(1);
  iVar3 = r_llc_proc_state_get();
  if (iVar3 == param_2) {
    iVar3 = r_llc_proc_state_get(iVar2);
    if (iVar3 == 3) {
      uVar1 = *(undefined2 *)(iVar2 + 0xe);
      *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) | 0x10;
      iVar3 = r_lld_con_ch_map_update(param_1,iVar2 + 8,uVar1);
      if (iVar3 == 0) {
        r_llc_proc_state_set(iVar2,param_1,4);
        return;
      }
    }
    else {
      if (iVar3 != 4) {
        uVar4 = r_llc_proc_state_get(iVar2);
        r_assert_param(param_1,uVar4,0x10000,0x11d);
        return;
      }
      memcpy((void *)(iVar5 + 8),(void *)(iVar2 + 8),5);
    }
  }
  *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) & 0xffef;
  r_llc_proc_unreg(param_1,1);
  return;
}

