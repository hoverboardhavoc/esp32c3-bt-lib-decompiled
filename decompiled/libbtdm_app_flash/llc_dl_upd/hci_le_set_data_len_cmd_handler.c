/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> hci_le_set_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_set_data_len_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  piVar4 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar4;
  iVar2 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*piVar4 != 0)) &&
     ((*(byte *)(*piVar4 + 0x44) & 3) != 3)) {
    bVar1 = *(byte *)(iVar5 + 0x45);
    uVar6 = bVar1 & 0x20;
    if ((bVar1 & 0x20) == 0) {
      iVar2 = r_sdk_config_get_opts();
      if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*piVar4 != 0)) &&
         (((int)(uint)*(byte *)(*piVar4 + 0x30) >> 5 & 1U) != 0)) {
        if (((ushort)(*(short *)(param_2 + 2) - 0x1bU) < 0xe1) &&
           ((ushort)(*(short *)(param_2 + 4) - 0x148U) < 0x4149)) {
          if ((*(short *)(iVar5 + 0x14) != *(short *)(param_2 + 2)) ||
             (*(short *)(iVar5 + 0x18) != *(short *)(param_2 + 4))) {
            puVar3 = (undefined4 *)r_ke_msg_alloc(0x10a,param_1 << 8 | 1,0x14);
            *(undefined1 *)(puVar3 + 1) = 7;
            r_llc_proc_state_set(param_1,0);
            *puVar3 = r_llc_dle_proc_err_cb;
            *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(param_2 + 2);
            *(undefined2 *)((int)puVar3 + 10) = *(undefined2 *)(param_2 + 4);
            puVar3[3] = 0x429000fb;
            *(undefined1 *)(puVar3 + 4) = 1;
            r_ke_msg_send(puVar3);
            *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 0x20;
          }
          *(undefined2 *)(iVar5 + 0x20) = *(undefined2 *)(param_2 + 2);
          *(undefined2 *)(iVar5 + 0x22) = *(undefined2 *)(param_2 + 4);
        }
        else {
          r_ble_log_internal_x2(0x802f002b,*(undefined4 *)(param_2 + 2),param_1);
          uVar6 = 0x12;
        }
      }
      else {
        r_ble_log_internal_x1(0x802f002a,param_1 << 8 | 0x1a);
        uVar6 = 0x1a;
      }
    }
    else {
      r_ble_log_internal_x1(0x802f0029,param_1 << 8 | (uint)bVar1 << 0x10 | 0x3a);
      uVar6 = 0x3a;
    }
  }
  else {
    r_ble_log_internal_x1(0x802f0028,param_1 << 8 | 0xc);
    uVar6 = 0xc;
  }
  r_llc_cmd_cmp_send(param_1,param_3,uVar6);
  return 0;
}

