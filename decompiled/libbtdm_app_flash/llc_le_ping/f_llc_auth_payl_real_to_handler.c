/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> f_llc_auth_payl_real_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_auth_payl_real_to_handler(uint param_1)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 >> 8;
  iVar4 = *(int *)(&llc_env + uVar3 * 4);
  iVar1 = r_sdk_config_get_opts();
  if (((uVar3 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + uVar3 * 4), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    if ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0) {
      r_ble_log_internal_x1(0x604f00b1,uVar3);
      puVar2 = (undefined2 *)r_ke_msg_alloc(0x1103,uVar3,0x57,2);
      *puVar2 = (short)(param_1 >> 8);
      r_hci_send_2_host();
      r_llc_le_ping_restart_hack(uVar3);
    }
  }
  else {
    r_ble_log_internal_x1(0x204f00b0,uVar3);
  }
  return 0;
}

