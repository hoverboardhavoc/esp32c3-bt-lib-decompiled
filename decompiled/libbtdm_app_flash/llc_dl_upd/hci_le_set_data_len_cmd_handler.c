/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> hci_le_set_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_set_data_len_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  piVar2 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar2;
  iVar3 = r_sdk_config_get_opts();
  bVar1 = 0xc;
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    bVar1 = 0xc;
    if ((*piVar2 != 0) && ((*(byte *)(*piVar2 + 0x44) & 3) != 3)) {
      bVar1 = *(byte *)(iVar5 + 0x45) & 0x20;
      if ((*(byte *)(iVar5 + 0x45) & 0x20) == 0) {
        iVar3 = r_sdk_config_get_opts();
        if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar2 != 0)) &&
           (((int)(uint)*(byte *)(*piVar2 + 0x30) >> 5 & 1U) != 0)) {
          if ((ushort)(*(short *)(param_2 + 2) - 0x1bU) < 0xe1) {
            if ((ushort)(*(short *)(param_2 + 4) - 0x148U) < 0x4149) {
              if ((*(short *)(iVar5 + 0x14) != *(short *)(param_2 + 2)) ||
                 (*(short *)(iVar5 + 0x18) != *(short *)(param_2 + 4))) {
                puVar4 = (undefined4 *)r_ke_msg_alloc(0x10a,param_1 << 8 | 1,0x14);
                *(undefined1 *)(puVar4 + 1) = 7;
                r_llc_proc_state_set(param_1,0);
                *puVar4 = r_llc_dle_proc_err_cb;
                *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_2 + 2);
                *(undefined2 *)((int)puVar4 + 10) = *(undefined2 *)(param_2 + 4);
                puVar4[3] = 0x429000fb;
                *(undefined1 *)(puVar4 + 4) = 1;
                r_ke_msg_send(puVar4);
                *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 0x20;
              }
              *(undefined2 *)(iVar5 + 0x20) = *(undefined2 *)(param_2 + 2);
              *(undefined2 *)(iVar5 + 0x22) = *(undefined2 *)(param_2 + 4);
              goto _L143;
            }
          }
          bVar1 = 0x12;
        }
        else {
          bVar1 = 0x1a;
        }
      }
      else {
        bVar1 = 0x3a;
      }
    }
  }
_L143:
  r_llc_cmd_cmp_send(param_1,param_3,bVar1);
  return 0;
}

