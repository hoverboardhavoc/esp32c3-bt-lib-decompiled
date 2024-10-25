/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> hci_le_rd_chnl_map_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rd_chnl_map_cmd_handler(uint param_1,undefined2 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uVar3;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,*param_2,0x2015,10);
  iVar2 = r_sdk_config_get_opts();
  uVar3 = 0xc;
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    memcpy(puVar1 + 4,(void *)(iVar2 + 8),5);
    uVar3 = 0;
  }
  *puVar1 = uVar3;
  *(undefined2 *)(puVar1 + 2) = *param_2;
  r_hci_send_2_host(puVar1);
  return 0;
}

