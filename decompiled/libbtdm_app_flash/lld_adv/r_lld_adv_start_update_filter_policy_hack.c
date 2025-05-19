/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_update_filter_policy_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_start_update_filter_policy_hack(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *__dest;
  ushort uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = *(int *)(&lld_adv_env + param_1 * 4);
  if (((*(byte *)(param_2 + 0x1e) & 2) != 0) &&
     (uVar3 = r_lld_ral_search(param_2 + 6,*(undefined1 *)(param_2 + 0x1f)), uVar3 < 10)) {
    iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
    if ((*(ushort *)(iVar4 + uVar3 * 0x34) >> 5 & 1) != 0) {
      uVar6 = 1;
      iVar9 = 1;
      iVar4 = 1;
      sVar7 = (short)uVar3 * 0x34 + 0xc60;
      goto _L69;
    }
    if (((*(ushort *)(iVar9 + 0x74) & 4) != 0) &&
       (iVar4 = r_emi_get_mem_addr_by_offset(0xc60),
       (*(ushort *)(uVar3 * 0x34 + iVar4) >> 1 & 1) != 0)) {
      uVar6 = 1;
      iVar9 = 1;
      iVar4 = 0;
      sVar7 = (short)((uVar3 * 0x34 + 0xc60) * 0x10000 >> 0x10);
      goto _L69;
    }
  }
  if (*(char *)(param_2 + 0x27) == '\0') {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(ushort *)(iVar9 + 0x74) >> 2 ^ 1) & 1;
  }
  iVar9 = 0;
  iVar4 = 0;
  sVar7 = 0;
_L69:
  bVar1 = *(byte *)(param_2 + 0x20);
  bVar2 = *(byte *)(param_2 + 0x27);
  iVar8 = param_1 * 0x5a;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + 0x14 + iVar5) =
       (ushort)bVar1 << 8 | (ushort)bVar2 << 6 | uVar6 | (ushort)(iVar4 << 2) | (ushort)(iVar9 << 1)
  ;
  if (iVar9 == 0) {
    __dest = (void *)r_emi_get_mem_addr_by_offset(param_1 * 0x5a + 0x42cU & 0xffff);
    memcpy(__dest,(void *)(param_2 + 6),6);
    bVar1 = *(byte *)(param_2 + 0x1f);
    if ((bVar1 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x79b);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar8 + 0x32 + iVar9) = (ushort)bVar1;
  }
  else {
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar8 + 0x2c + iVar9) = sVar7;
  }
  return;
}

