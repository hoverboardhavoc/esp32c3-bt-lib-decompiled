/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chm_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chm_restore(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  
  iVar4 = r_lld_read_clock();
  iVar2 = p_lld_cca;
  uVar8 = 0;
  do {
    pbVar7 = (byte *)(uVar8 * 0xc + *(int *)(iVar2 + 0x28));
    bVar1 = *pbVar7;
    if ((bVar1 & 4) != 0) {
      uVar3 = (uint)*(byte *)(iVar2 + 0x25) * 0x280;
      uVar5 = (uint)*(ushort *)(iVar2 + 0x12) << 1;
      if (uVar5 < uVar3) {
        uVar5 = uVar3;
      }
      if (uVar5 <= (iVar4 - *(int *)(pbVar7 + 4) & 0xfffffffU)) {
        pbVar6 = (byte *)(*(int *)(iVar2 + 0x1c) + ((uVar8 & 0xff) >> 3));
        *pbVar6 = (byte)(1 << (uVar8 & 7)) | *pbVar6;
        *pbVar7 = bVar1 & 0xf9 | 1;
      }
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0x28);
  return;
}

