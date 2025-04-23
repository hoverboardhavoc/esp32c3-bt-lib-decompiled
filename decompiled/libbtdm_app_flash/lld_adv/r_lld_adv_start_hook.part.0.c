/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_hook.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_start_hook_part_0(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  
  sVar2 = DAT_00016464;
  if (((DAT_00016464 != 0) && (DAT_00016466 != 0)) && (*(int *)(&lld_adv_env + param_1 * 4) != 0)) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 * 0x5a + 0xc + iVar4) = sVar2;
    sVar2 = DAT_00016466;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 * 0x5a + 0xe + iVar4) = sVar2;
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar4 + 0x18) == '\0') && ((*(ushort *)(param_2 + 0x18) & 0x10) != 0)) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = param_1 * 9 & 0xff;
    iVar8 = uVar3 * 0xe + 2;
    uVar1 = *(ushort *)(iVar4 + iVar8);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar8) = uVar1 & 0xffdf;
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = (uVar3 + 1 & 0xff) * 0xe + 2;
    uVar1 = *(ushort *)(iVar8 + iVar4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar4) = uVar1 & 0xffdf;
  }
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar8 = llm_csa_get();
  cVar6 = '\x02';
  if ((*(ushort *)(iVar4 + 0x74) & 0x10) == 0) {
    cVar6 = *(char *)(iVar4 + 0x92);
  }
  if (iVar8 != 0) {
    iVar4 = param_1 * 0x7e + 2;
    for (cVar7 = '\0'; cVar7 != cVar6; cVar7 = cVar7 + '\x01') {
      if ((iVar8 - 1U & 0xfe) != 0) {
        r_assert_err(0,0x10000,0x162);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar5 + iVar4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + iVar4) = uVar1 & 0xffdf | (ushort)((iVar8 - 1U & 0xff) << 5);
      iVar4 = iVar4 + 0xe;
    }
  }
  lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x1e));
  return;
}

