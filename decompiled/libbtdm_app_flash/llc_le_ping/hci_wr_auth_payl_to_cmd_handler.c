/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> hci_wr_auth_payl_to_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_wr_auth_payl_to_cmd_handler(uint param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,*param_2,0xc7c,4);
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar3 + 0x20) != '\0') {
      uVar1 = r_llc_le_ping_set(param_1,param_2[1]);
      goto _L93;
    }
  }
  uVar1 = 0xc;
_L93:
  *puVar2 = uVar1;
  *(undefined2 *)(puVar2 + 2) = *param_2;
  r_hci_send_2_host(puVar2);
  return 0;
}

