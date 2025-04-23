/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> llm_ch_map_update_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_ch_map_update_ind_handler(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = param_1 >> 8;
  iVar2 = r_sdk_config_get_opts();
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + uVar1 * 4), iVar2 != 0)) &&
     ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    if ((*(ushort *)(iVar2 + 0x42) & 0x100) == 0) {
      puVar3 = (undefined4 *)r_ke_msg_alloc(0x10d,param_1,0x10);
      *(undefined1 *)(puVar3 + 1) = 6;
      r_llc_proc_state_set(uVar1,0);
      *puVar3 = r_llc_ch_map_up_proc_err_cb;
      r_ke_msg_send(puVar3);
      *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) | 0x100;
    }
  }
  return 0;
}

