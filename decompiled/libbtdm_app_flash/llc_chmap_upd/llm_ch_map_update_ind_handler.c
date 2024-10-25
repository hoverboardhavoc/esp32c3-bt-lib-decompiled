/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> llm_ch_map_update_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llm_ch_map_update_ind_handler(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = param_1 >> 8;
  iVar1 = r_sdk_config_get_opts();
  if (((uVar3 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + uVar3 * 4), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    if ((*(ushort *)(iVar1 + 0x42) & 0x100) == 0) {
      puVar2 = (undefined4 *)r_ke_msg_alloc(0x10d,param_1,0x10);
      *(undefined1 *)(puVar2 + 1) = 6;
      r_llc_proc_state_set(uVar3,0);
      *puVar2 = r_llc_ch_map_up_proc_err_cb;
      r_ke_msg_send(puVar2);
      *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) | 0x100;
    }
  }
  return 0;
}

