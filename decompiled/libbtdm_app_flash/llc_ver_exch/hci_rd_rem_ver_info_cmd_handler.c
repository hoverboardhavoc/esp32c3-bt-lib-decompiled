/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_ver_exch.o -> hci_rd_rem_ver_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_rd_rem_ver_info_cmd_handler(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + param_1 * 4);
    bVar1 = 0xc;
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      bVar1 = *(byte *)(iVar4 + 0x45) & 2;
      if ((*(byte *)(iVar4 + 0x45) & 2) == 0) {
        puVar3 = (undefined4 *)r_ke_msg_alloc(0x106,param_1 << 8 | 1,0xc);
        *(undefined1 *)(puVar3 + 1) = 2;
        r_llc_proc_state_set(param_1,0);
        *puVar3 = r_llc_ver_proc_err_cb;
        *(undefined1 *)(puVar3 + 2) = 1;
        r_ke_msg_send(puVar3);
        *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) | 2;
      }
      else {
        bVar1 = 0x3a;
      }
    }
  }
  else {
    bVar1 = 0xc;
  }
  r_llc_cmd_stat_send(param_1,param_2,bVar1);
  return 0;
}

