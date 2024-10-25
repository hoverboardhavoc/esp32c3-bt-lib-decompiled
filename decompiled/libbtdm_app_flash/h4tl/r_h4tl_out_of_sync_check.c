/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_out_of_sync_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_h4tl_out_of_sync_check(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  
  local_20 = 0xc0301;
  iVar1 = memcmp(&local_20,(void *)(param_1 + 0x10),4);
  if (iVar1 == 0) {
    r_hci_cmd_received(0xc03,0,0);
  }
  else {
    memcpy(auStack_1c,&DAT_000107bc,10);
    iVar1 = memcmp(auStack_1c,(undefined1 *)(param_1 + 10),10);
    if (iVar1 != 0) {
      r_rwip_prevent_sleep_set(4);
      puVar2 = (undefined1 *)(param_1 + 10);
      do {
        puVar3 = puVar2 + 1;
        *puVar2 = puVar2[1];
        puVar2 = puVar3;
      } while (puVar3 != (undefined1 *)(param_1 + 0x13));
      return 0;
    }
    puVar2 = (undefined1 *)r_ke_msg_alloc(1,8,0x1e,1);
    *puVar2 = 1;
    r_ke_msg_send();
  }
  return 1;
}

