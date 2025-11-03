/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_ble_adv_report_filter_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_hci_ble_adv_report_filter_check(int param_1)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  
  if (*(short *)(param_1 + 4) == 0x1104) {
    cVar3 = *(char *)(param_1 + 0xc);
    if (cVar3 == '\r') {
      uVar4 = (int)(uint)*(ushort *)(param_1 + 0xe) >> 5 & 3;
      cVar3 = DAT_00012022;
      if (*(char *)(param_1 + 0x17) == '\x01') {
        cVar3 = DAT_00012021;
      }
      if ((cVar3 == '\x02') || ((cVar3 == '\0' && (3 < (byte)r_co_util_unpack)))) {
        cVar3 = (uVar4 == 1) << 1;
        bVar2 = true;
      }
      else {
        cVar3 = uVar4 == 1;
        bVar2 = false;
      }
      if (*(char *)(param_1 + 0x17) == '\x01') {
        DAT_00012021 = cVar3;
        cVar3 = DAT_00012022;
      }
      DAT_00012022 = cVar3;
      if (bVar2) goto _L23;
    }
    else if (cVar3 == '\x0f') {
      bVar1 = *(byte *)(param_1 + 0xe);
      if (((&DAT_00012023)[bVar1] == '\x02') ||
         (((&DAT_00012023)[bVar1] == '\0' && (3 < (byte)r_co_util_unpack)))) {
        (&DAT_00012023)[bVar1] = (*(char *)(param_1 + 0x13) == '\x01') << 1;
        goto _L23;
      }
      (&DAT_00012023)[bVar1] = *(char *)(param_1 + 0x13) == '\x01';
    }
    else {
      if (cVar3 != '\x02') {
        return 0;
      }
      if (3 < hci_tl_env) {
_L23:
        r_ke_msg_free();
        return 1;
      }
    }
    r_co_util_unpack = (code)((char)r_co_util_unpack + '\x01');
  }
  return 0;
}

