/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar4 + 0x18) == '\0') {
    bVar1 = *(byte *)(param_1 + 0x13);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = ((uint)bVar1 * 9 & 0xff) * 0xe + 2;
    uVar2 = *(ushort *)(iVar5 + iVar4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar4) = uVar2 & 0xffdf;
  }
  iVar4 = llm_csa_get();
  if (iVar4 != 0) {
    uVar3 = (iVar4 - 1U & 0xff) << 5;
    bVar1 = *(byte *)(param_1 + 0x13);
    if ((uVar3 & 0xffffffdf) != 0) {
      r_assert_err(0,0x10000,0x162);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar5 = (uint)bVar1 * 0x7e + 2;
    uVar2 = *(ushort *)(iVar4 + iVar5);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar5) = uVar2 & 0xffdf | (ushort)uVar3;
  }
  lld_rpa_renew_start(*(undefined1 *)(param_1 + 0x14));
  return;
}

