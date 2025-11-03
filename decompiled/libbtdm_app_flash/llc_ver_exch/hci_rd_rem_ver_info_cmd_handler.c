/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_sdk_config_get_opts();
  uVar4 = param_1 << 8;
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    bVar1 = *(byte *)(iVar6 + 0x45);
    uVar5 = bVar1 & 2;
    if ((bVar1 & 2) == 0) {
      puVar3 = (undefined4 *)r_ke_msg_alloc(0x106,uVar4 | 1,0xc);
      *(undefined1 *)(puVar3 + 1) = 2;
      r_llc_proc_state_set(param_1,0);
      *puVar3 = r_llc_ver_proc_err_cb;
      *(undefined1 *)(puVar3 + 2) = 1;
      r_ke_msg_send(puVar3);
      *(byte *)(iVar6 + 0x45) = *(byte *)(iVar6 + 0x45) | 2;
    }
    else {
      r_ble_log_internal_x1(0x8003004b,uVar4 | (uint)bVar1 << 0x10 | 0x3a);
      uVar5 = 0x3a;
    }
  }
  else {
    r_ble_log_internal_x1(0x8003004a,uVar4 | 0xc);
    uVar5 = 0xc;
  }
  r_llc_cmd_stat_send(param_1,param_2,uVar5);
  return 0;
}

