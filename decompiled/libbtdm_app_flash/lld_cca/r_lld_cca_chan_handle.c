/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chan_handle(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  r_lld_cca_busy_mode_handle();
  if (param_1 != 0) {
    return;
  }
  uVar5 = (uint)*(ushort *)(p_lld_cca + 0xe);
  if (*(ushort *)(p_lld_cca + 0x10) < uVar5) {
    uVar2 = *(ushort *)(p_lld_cca + 4) >> 0xc;
    if (uVar2 == 1) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = *(ushort *)(p_lld_cca + 0x10) - *(short *)(p_lld_cca + 0x14);
    }
    else {
      if (uVar2 != 2) {
        return;
      }
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = (short)(((uVar5 - *(ushort *)(p_lld_cca + 0x14)) + (int)uVar5 / -0x14) * 0x10000 >>
                     0x10);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + (uint)bVar1 * 0x5a + 0x20) = sVar3;
    return;
  }
  return;
}

