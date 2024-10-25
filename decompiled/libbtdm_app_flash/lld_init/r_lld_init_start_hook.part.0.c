/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_start_hook.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_init_start_hook_part_0(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x18) == '\0') {
    bVar1 = *(byte *)(param_1 + 0x13);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar3 = ((uint)bVar1 * 9 & 0xff) * 0xe + 2;
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar3) = uVar2 & 0xffdf;
  }
  iVar3 = llm_csa_get();
  if (iVar3 != 0) {
    uVar5 = (iVar3 - 1U & 0xff) << 5;
    bVar1 = *(byte *)(param_1 + 0x13);
    if ((uVar5 & 0xffffffdf) != 0) {
      r_assert_err(0,"lld_init.c",0x162);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = (uint)bVar1 * 0x7e + 2;
    uVar2 = *(ushort *)(iVar3 + iVar4);
    iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar3 + iVar4) = uVar2 & 0xffdf | (ushort)uVar5;
  }
  lld_rpa_renew_start(*(undefined1 *)(param_1 + 0x14));
  return;
}

