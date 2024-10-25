/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> r_llc_hci_feats_info_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_hci_feats_info_send(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1104,param_1,0,0xc);
  puVar1[1] = param_2;
  *(short *)(puVar1 + 2) = (short)param_1;
  *puVar1 = 4;
  memcpy(puVar1 + 4,param_3,8);
  r_hci_send_2_host(puVar1);
  return;
}

