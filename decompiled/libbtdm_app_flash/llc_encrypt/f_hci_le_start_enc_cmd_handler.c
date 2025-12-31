/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> f_hci_le_start_enc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_hci_le_start_enc_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  piVar2 = (int *)(&llc_env + param_1 * 4);
  iVar7 = *piVar2;
  iVar3 = r_sdk_config_get_opts();
  uVar5 = param_1 << 8;
  if ((((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar2 != 0)) &&
      ((*(byte *)(*piVar2 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar7 + 0x42) & 1) != 0)) {
    iVar3 = r_sdk_config_get_opts();
    if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar2 != 0)) &&
       ((*(byte *)(*piVar2 + 0x30) & 1) != 0)) {
      bVar1 = *(byte *)(iVar7 + 0x45);
      uVar6 = bVar1 & 8;
      if ((bVar1 & 8) == 0) {
        puVar4 = (undefined4 *)r_ke_msg_alloc(0x109,uVar5 | 1,0x3c);
        *(undefined1 *)(puVar4 + 1) = 3;
        r_llc_proc_state_set(param_1,0);
        *puVar4 = r_llc_loc_encrypt_proc_err_cb;
        memcpy(puVar4 + 2,(void *)(param_2 + 2),8);
        *(undefined2 *)(puVar4 + 0xe) = *(undefined2 *)(param_2 + 10);
        memcpy(puVar4 + 4,(void *)(param_2 + 0xc),0x10);
        *(byte *)((int)puVar4 + 0x3a) = (byte)((int)(uint)*(ushort *)(iVar7 + 0x42) >> 5) & 1;
        r_ke_msg_send(puVar4);
        *(byte *)(iVar7 + 0x45) = *(byte *)(iVar7 + 0x45) | 8;
      }
      else {
        r_ble_log_internal_x1(0x80030092,(uint)bVar1 << 0x10 | uVar5 | 0x3a);
        uVar6 = 0x3a;
      }
    }
    else {
      r_ble_log_internal_x1(0x80030091,uVar5 | 0x1a);
      uVar6 = 0x1a;
    }
  }
  else {
    r_ble_log_internal_x1(0x80030090,uVar5 | 0xc);
    uVar6 = 0xc;
  }
  r_llc_cmd_stat_send(param_1,param_3,uVar6);
  return 0;
}

