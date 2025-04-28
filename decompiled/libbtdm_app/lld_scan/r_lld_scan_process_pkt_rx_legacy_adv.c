/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_legacy_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_legacy_adv(int param_1,uint param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  byte bVar5;
  code *pcVar6;
  int iVar7;
  undefined1 auStack_28 [8];
  
  if (6 < param_2) {
    return;
  }
  iVar2 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar1 = *(short *)(param_3 * 0x14 + 0x12 + iVar3);
  pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (sVar1 + (ushort)*(byte *)(param_4 + 3),
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(auStack_28,pvVar4,6);
  if ((param_2 == 4) && (iVar3 = memcmp(auStack_28,(void *)(iVar2 + 0x5c),6), iVar3 != 0)) {
    *(undefined1 *)(iVar2 + 0x6e) = 0xff;
    return;
  }
  memset((void *)(iVar2 + 0x58),0,0x2c);
  iVar3 = _r_plf_funcs_p;
  iVar7 = param_3 * 0x14 + 4;
  if (param_2 == 1) {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(byte *)(iVar2 + 0x70) = (byte)(*(ushort *)(iVar3 + iVar7) >> 7) & 1;
    *(undefined1 *)(param_4 + 2) = 6;
  }
  else {
    *(undefined1 *)(param_4 + 4) = 6;
    *(undefined1 *)(param_4 + 3) = 0;
    iVar3 = (**(code **)(iVar3 + 0xbc))(0x1000,*(code **)(iVar3 + 0xbc));
    *(char *)(param_4 + 5) =
         (char)((ushort)*(undefined2 *)(iVar3 + iVar7) >> 8) - *(char *)(param_4 + 4);
  }
  *(undefined *)(iVar2 + 0x6d) = (&lld_scan_map_legacy_pdu_to_evt_type)[param_2];
  if ((param_2 == 4) && (*(char *)(iVar2 + 0x3f) == '\x06')) {
    *(undefined1 *)(iVar2 + 0x6d) = 0x1a;
  }
  *(undefined2 *)(iVar2 + 0x72) = 0x7f04;
  iVar3 = _r_plf_funcs_p;
  *(undefined1 *)(iVar2 + 0x6e) = 0;
  *(undefined1 *)(iVar2 + 0x71) = 0;
  pcVar6 = *(code **)(iVar3 + 0xbc);
  *(undefined1 *)(iVar2 + 0x6a) = 0;
  iVar3 = (*pcVar6)(0x1000,pcVar6);
  bVar5 = (byte)(*(ushort *)(iVar3 + iVar7) >> 6) & 1;
  *(byte *)(param_4 + 8) = bVar5;
  *(byte *)(iVar2 + 0x6f) = bVar5;
  pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (sVar1 + (ushort)*(byte *)(param_4 + 3),
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy((void *)(iVar2 + 0x5c),pvVar4,6);
  return;
}

