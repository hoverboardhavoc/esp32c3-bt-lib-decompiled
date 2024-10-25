/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar4;
  void *pvVar5;
  byte bVar6;
  code *pcVar7;
  undefined1 auStack_28 [8];
  
  if (6 < param_2) {
    return;
  }
  iVar2 = *(int *)(param_1 * 4 + _lld_scan_env);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar1 = *(short *)(iVar4 + param_3 * 0x14 + 0x12);
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             ((ushort)*(byte *)(param_4 + 3) + sVar1,
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(auStack_28,pvVar5,6);
  if ((param_2 == 4) && (iVar4 = memcmp(auStack_28,(void *)(iVar2 + 0x5c),6), iVar4 != 0)) {
    *(undefined1 *)(iVar2 + 0x6e) = 0xff;
    return;
  }
  memset((void *)(iVar2 + 0x58),0,0x2c);
  iVar4 = _r_plf_funcs_p;
  iVar3 = param_3 * 0x14 + 4;
  if (param_2 == 1) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(byte *)(iVar2 + 0x70) = (byte)(*(ushort *)(iVar4 + iVar3) >> 7) & 1;
    *(undefined1 *)(param_4 + 2) = 6;
  }
  else {
    *(undefined1 *)(param_4 + 4) = 6;
    *(undefined1 *)(param_4 + 3) = 0;
    iVar4 = (**(code **)(iVar4 + 0xbc))(0x1000,*(code **)(iVar4 + 0xbc));
    *(char *)(param_4 + 5) =
         (char)((ushort)*(undefined2 *)(iVar4 + iVar3) >> 8) - *(char *)(param_4 + 4);
  }
  *(undefined *)(iVar2 + 0x6d) = (&lld_scan_map_legacy_pdu_to_evt_type)[param_2];
  if ((param_2 == 4) && (*(char *)(iVar2 + 0x3f) == '\x06')) {
    *(undefined1 *)(iVar2 + 0x6d) = 0x1a;
  }
  *(undefined2 *)(iVar2 + 0x72) = 0x7f04;
  iVar4 = _r_plf_funcs_p;
  *(undefined1 *)(iVar2 + 0x6e) = 0;
  *(undefined1 *)(iVar2 + 0x71) = 0;
  pcVar7 = *(code **)(iVar4 + 0xbc);
  *(undefined1 *)(iVar2 + 0x6a) = 0;
  iVar4 = (*pcVar7)(0x1000,pcVar7);
  bVar6 = (byte)(*(ushort *)(iVar4 + iVar3) >> 6) & 1;
  *(byte *)(param_4 + 8) = bVar6;
  *(byte *)(iVar2 + 0x6f) = bVar6;
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             ((ushort)*(byte *)(param_4 + 3) + sVar1,
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy((void *)(iVar2 + 0x5c),pvVar5,6);
  return;
}

