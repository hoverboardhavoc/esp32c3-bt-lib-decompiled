/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> llc_auth_payl_real_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
llc_auth_payl_real_to_handler(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0;
  }
  uVar3 = param_3 >> 8;
  iVar4 = *(int *)(&llc_env + uVar3 * 4);
  iVar2 = r_sdk_config_get_opts(param_1,param_2,param_4);
  if (((uVar3 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + uVar3 * 4), iVar2 != 0)) &&
     ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    if ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0) {
      r_ble_log_internal_x1(0x604f00b1,uVar3);
      puVar1 = (undefined2 *)r_ke_msg_alloc(0x1103,uVar3,0x57,2);
      *puVar1 = (short)(param_3 >> 8);
      r_hci_send_2_host();
      r_llc_le_ping_restart_hack(uVar3);
    }
  }
  else {
    r_ble_log_internal_x1(0x204f00b0,uVar3);
  }
  return 0;
}

