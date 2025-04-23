/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> f_llc_auth_payl_nearly_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_auth_payl_nearly_to_handler(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 >> 8;
  iVar4 = *(int *)(&llc_env + uVar3 * 4);
  iVar1 = r_sdk_config_get_opts();
  if (((uVar3 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + uVar3 * 4), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    if ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0) {
      puVar2 = (undefined4 *)r_ke_msg_alloc(0x10c,param_1,8);
      *(undefined1 *)(puVar2 + 1) = 8;
      r_llc_proc_state_set(uVar3,0);
      *puVar2 = r_llc_le_ping_proc_err_cb;
      r_ke_msg_send(puVar2);
    }
  }
  return 0;
}

