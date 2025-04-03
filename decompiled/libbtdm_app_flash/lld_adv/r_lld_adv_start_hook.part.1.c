/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_hook.part.1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_start_hook_part_1(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  char cVar7;
  
  sVar2 = DAT_000164c0;
  if (((DAT_000164c0 != 0) && (DAT_000164c2 != 0)) && (*(int *)(&lld_adv_env + param_1 * 4) != 0)) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + param_1 * 0x5a + 0xc) = sVar2;
    sVar2 = DAT_000164c2;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 * 0x5a + 0xe + iVar4) = sVar2;
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar4 + 0x18) == '\0') && ((*(ushort *)(param_2 + 0x18) & 0x10) != 0)) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = param_1 * 9 & 0xff;
    iVar6 = uVar3 * 0xe + 2;
    uVar1 = *(ushort *)(iVar4 + iVar6);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar6) = uVar1 & 0xffdf;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = (uVar3 + 1 & 0xff) * 0xe + 2;
    uVar1 = *(ushort *)(iVar6 + iVar4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar4) = uVar1 & 0xffdf;
  }
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar6 = llm_csa_get();
  cVar5 = '\x02';
  if ((*(ushort *)(iVar4 + 0x74) & 0x10) == 0) {
    cVar5 = *(char *)(iVar4 + 0x92);
  }
  if (iVar6 != 0) {
    param_1 = param_1 * 0x7e;
    for (cVar7 = '\0'; cVar7 != cVar5; cVar7 = cVar7 + '\x01') {
      if ((iVar6 - 1U & 0xfe) != 0) {
        r_assert_err(0,"lld_adv.c",0x162);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar4 + param_1 + 2);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + param_1 + 2) =
           uVar1 & 0xffdf | (ushort)(((iVar6 - 1U & 0xff) << 0x15) >> 0x10);
      param_1 = param_1 + 0xe;
    }
  }
  lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x1e));
  return;
}

