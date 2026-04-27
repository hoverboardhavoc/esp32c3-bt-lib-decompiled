/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_eco(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  iVar7 = *(int *)(&lld_con_env + param_1 * 4);
  bVar1 = *(byte *)(iVar7 + 0x8e);
  bVar2 = *(byte *)(iVar7 + 0x90);
  if (*(short *)(iVar7 + 0x84) < 0) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = ((uint)bVar2 + (uint)bVar1 * 9 & 0xff) * 0xe;
    if (*(short *)(iVar5 + iVar4) < 0) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar5 + iVar4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      *(ushort *)(iVar7 + 0x84) = *(ushort *)(iVar7 + 0x84) | 0x800;
    }
  }
  r_lld_con_tx(param_1);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  pcVar6 = (char *)(iVar4 + param_1 * 4);
  if (((*pcVar6 != '\0') && (pcVar6[2] == '\0')) &&
     (param_1 * 9 + (uint)*(byte *)(iVar7 + 0x90) == (uint)(byte)pcVar6[1])) {
    pcVar6[2] = '\x01';
  }
  return;
}

