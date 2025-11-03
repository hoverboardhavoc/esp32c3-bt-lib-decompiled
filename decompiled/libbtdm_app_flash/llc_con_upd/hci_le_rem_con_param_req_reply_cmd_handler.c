/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> hci_le_rem_con_param_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rem_con_param_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    uVar3 = 0x20;
    iVar1 = r_llc_con_upd_param_in_range
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
    if (iVar1 == 0) goto _L272;
    iVar1 = r_llc_proc_get(param_1,1);
    if (iVar1 != 0) {
      uVar2 = *(ushort *)(iVar1 + 10);
      if (*(ushort *)(iVar1 + 10) < *(ushort *)(param_2 + 4)) {
        uVar2 = *(ushort *)(param_2 + 4);
      }
      *(ushort *)(iVar1 + 10) = uVar2;
      uVar2 = *(ushort *)(iVar1 + 8);
      if (*(ushort *)(iVar1 + 8) < *(ushort *)(param_2 + 2)) {
        uVar2 = *(ushort *)(param_2 + 2);
      }
      *(ushort *)(iVar1 + 8) = uVar2;
      uVar2 = *(ushort *)(iVar1 + 0xe);
      if (*(ushort *)(iVar1 + 0xe) < *(ushort *)(param_2 + 8)) {
        uVar2 = *(ushort *)(param_2 + 8);
      }
      *(ushort *)(iVar1 + 0xe) = uVar2;
      r_llc_rem_con_upd_proc_continue_hack(param_1,8,0);
      uVar3 = 0;
      goto _L272;
    }
  }
  uVar3 = 0xc;
_L272:
  r_llc_cmd_cmp_send(param_1,param_3,uVar3);
  if (uVar3 != 0) {
    r_ble_log_internal_x1(0x802f0024,param_1 << 8 | uVar3);
  }
  return 0;
}

