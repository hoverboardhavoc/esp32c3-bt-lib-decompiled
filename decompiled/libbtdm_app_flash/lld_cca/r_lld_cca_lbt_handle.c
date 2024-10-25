/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_lbt_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_lbt_handle(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  pbVar4 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if (((int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xfU) == 2) {
    r_lld_cca_set_thresh(0);
    *pbVar4 = *pbVar4 & 0x7f;
  }
  else {
    r_lld_cca_set_thresh((int)*(char *)(p_lld_cca + 7));
  }
  if (*(ushort *)(p_lld_cca + 4) >> 0xc == 1) {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    sVar2 = *(short *)(p_lld_cca + 0x10);
    sVar3 = *(short *)(p_lld_cca + 0x14);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar5 + (uint)bVar1 * 0x5a + 0x20) = sVar2 - sVar3;
  }
  uVar6 = (uint)rwip_prog_delay;
  *pbVar4 = *pbVar4 & 0xf5 | 0x41;
  *(uint *)(pbVar4 + 4) = (uVar6 - 1) + param_1;
  return;
}

