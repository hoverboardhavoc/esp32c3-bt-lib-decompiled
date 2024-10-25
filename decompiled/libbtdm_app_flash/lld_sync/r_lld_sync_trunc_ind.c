/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_trunc_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_trunc_ind(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x204,0,0xff,0x1c);
  r_lld_sync_scan_dynamic_pti_process(*(undefined4 *)(&lld_sync_env + param_1 * 4),2);
  puVar1[0xb] = 0x7f;
  *puVar1 = (char)param_1;
  *(undefined2 *)(puVar1 + 0xc) = 0x27f;
  puVar1[0xe] = 0;
  r_ke_msg_send(puVar1);
  return;
}

