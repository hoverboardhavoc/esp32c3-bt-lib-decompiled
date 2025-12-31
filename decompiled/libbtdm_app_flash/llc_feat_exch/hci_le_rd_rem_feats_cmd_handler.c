/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> hci_le_rd_rem_feats_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rd_rem_feats_cmd_handler(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  piVar2 = (int *)(&llc_env + param_1 * 4);
  iVar6 = *piVar2;
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar2 != 0)) &&
     ((*(byte *)(*piVar2 + 0x44) & 3) != 3)) {
    bVar1 = *(byte *)(iVar6 + 0x45);
    uVar5 = bVar1 & 4;
    if ((bVar1 & 4) == 0) {
      iVar3 = r_sdk_config_get_opts();
      if (((*(byte *)(iVar3 + 0xd) <= param_1) || (*piVar2 == 0)) ||
         (((int)(uint)*(byte *)(*piVar2 + 0x30) >> 3 & 1U) == 0)) {
        if ((*(ushort *)(iVar6 + 0x42) & 0x81) == 0) {
          r_ble_log_internal_x1
                    (0x8003009b,param_1 << 0x18 | (uint)*(ushort *)(iVar6 + 0x42) | 0x1a0000);
          uVar5 = 0x1a;
          goto _L58;
        }
      }
      puVar4 = (undefined4 *)r_ke_msg_alloc(0x107,param_1 << 8 | 1,0xc);
      *(undefined1 *)(puVar4 + 1) = 4;
      r_llc_proc_state_set(param_1,0);
      *(undefined1 *)(puVar4 + 2) = 1;
      *puVar4 = r_llc_feats_exch_proc_err_cb;
      r_ke_msg_send(puVar4);
      *(byte *)(iVar6 + 0x45) = *(byte *)(iVar6 + 0x45) | 4;
    }
    else {
      r_ble_log_internal_x1(0x8003009a,param_1 << 8 | (uint)bVar1 << 0x10 | 0x3a);
      uVar5 = 0x3a;
    }
  }
  else {
    r_ble_log_internal_x1(0x80030099,param_1 << 8 | 0xc);
    uVar5 = 0xc;
  }
_L58:
  r_llc_cmd_stat_send(param_1,param_2,uVar5);
  return 0;
}

