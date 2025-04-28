/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> hci_le_start_enc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_start_enc_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar4 + 0x20) == '\0') {
    r_llc_cmd_stat_send(param_1,param_3,0xc);
    return 0;
  }
  piVar2 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar2;
  iVar4 = r_sdk_config_get_opts();
  bVar1 = 0xc;
  if (param_1 < *(byte *)(iVar4 + 0xd)) {
    bVar1 = 0xc;
    if (((*piVar2 != 0) && ((*(byte *)(*piVar2 + 0x44) & 3) != 3)) &&
       ((*(ushort *)(iVar5 + 0x42) & 1) != 0)) {
      iVar4 = r_sdk_config_get_opts();
      bVar1 = 0x1a;
      if (((param_1 < *(byte *)(iVar4 + 0xd)) && (*piVar2 != 0)) &&
         ((*(byte *)(*piVar2 + 0x30) & 1) != 0)) {
        bVar1 = *(byte *)(iVar5 + 0x45) & 8;
        if ((*(byte *)(iVar5 + 0x45) & 8) == 0) {
          puVar3 = (undefined4 *)r_ke_msg_alloc(0x109,param_1 << 8 | 1,0x3c);
          *(undefined1 *)(puVar3 + 1) = 3;
          r_llc_proc_state_set(param_1,0);
          *puVar3 = r_llc_loc_encrypt_proc_err_cb;
          memcpy(puVar3 + 2,(void *)(param_2 + 2),8);
          *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(param_2 + 10);
          memcpy(puVar3 + 4,(void *)(param_2 + 0xc),0x10);
          *(byte *)((int)puVar3 + 0x3a) = (byte)((int)(uint)*(ushort *)(iVar5 + 0x42) >> 5) & 1;
          r_ke_msg_send(puVar3);
          *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 8;
        }
        else {
          bVar1 = 0x3a;
        }
      }
    }
  }
  r_llc_cmd_stat_send(param_1,param_3,bVar1);
  return 0;
}

