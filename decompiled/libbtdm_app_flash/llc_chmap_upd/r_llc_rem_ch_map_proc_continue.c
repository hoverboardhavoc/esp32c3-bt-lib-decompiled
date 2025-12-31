/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> r_llc_rem_ch_map_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_ch_map_proc_continue(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llc_proc_get(1);
  r_ble_log_internal_x2
            (0x404f007e,(uint)*(ushort *)(iVar5 + 0x42) | param_1 << 0x10 | param_2 << 0x18,param_3)
  ;
  iVar3 = r_llc_proc_state_get(iVar2);
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
        r_assert_param(param_1,uVar4,0x10000,0x122);
        return;
      }
      memcpy((void *)(iVar5 + 8),(void *)(iVar2 + 8),5);
    }
  }
  *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) & 0xffef;
  r_llc_proc_unreg(param_1,1);
  return;
}

