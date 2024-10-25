/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_send_empty_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_send_empty_packet(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = p_lld_cca;
  if (param_1 == 0) {
    sVar2 = *(short *)(p_lld_cca + 0x18);
    if (sVar2 != 0) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar3 = r_emi_get_mem_addr_by_offset(0x400);
      iVar4 = p_lld_cca;
      *(short *)(iVar3 + (uint)bVar1 * 0x5a + 0x1c) = sVar2;
      *(undefined2 *)(iVar4 + 0x18) = 0;
    }
  }
  else {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar4 + 0x18) = *(undefined2 *)((uint)bVar1 * 0x5a + 0x1c + iVar3);
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar4 + (uint)bVar1 * 0x5a + 0x1c) = 0;
  }
  return;
}

