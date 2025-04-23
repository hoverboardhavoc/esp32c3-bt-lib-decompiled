/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_multiplication_event_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_multiplication_event_handler(void)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_78 [2];
  undefined2 local_76 [17];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [2];
  undefined2 auStack_4a [17];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  (**(code **)(_r_modules_funcs_p + 0xec))(1,*(code **)(_r_modules_funcs_p + 0xec));
  iVar3 = (**(code **)(_r_modules_funcs_p + 0x40))(&ecc_env,*(code **)(_r_modules_funcs_p + 0x40));
  if (iVar3 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))("ecc_p256.c",0x857,*(code **)(_r_plf_funcs_p + 8));
  }
  else if (*(int *)(iVar3 + 4) == 0) {
    if (*(short *)(iVar3 + 0x13e) != 0xff) {
      puVar4 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (*(undefined2 *)(iVar3 + 0x13c),0x40,*(code **)(_r_modules_funcs_p + 200));
      memset(auStack_78,0,0x22);
      uStack_54 = 0;
      uStack_50 = 0;
      memset(auStack_4c,0,0x22);
      uStack_28 = 0;
      uStack_24 = 0;
      (**(code **)(_r_modules_funcs_p + 0x390))
                (iVar3 + 8,auStack_78,auStack_4c,*(code **)(_r_modules_funcs_p + 0x390));
      if (*(int *)(iVar3 + 0x148) != 0) {
        (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      }
      (**(code **)(_r_modules_funcs_p + 0x110))(iVar3,*(code **)(_r_modules_funcs_p + 0x110));
      puVar5 = local_76;
      puVar6 = puVar4 + 0x1e;
      do {
        uVar2 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6[1] = (char)((ushort)uVar2 >> 8);
        *puVar6 = (char)uVar2;
        bVar1 = puVar6 != puVar4;
        puVar6 = puVar6 + -2;
      } while (bVar1);
      puVar8 = auStack_78;
      puVar6 = puVar4 + 0x3e;
      do {
        uVar2 = *(undefined2 *)(puVar8 + 0x2e);
        puVar7 = puVar6 + -2;
        puVar8 = puVar8 + 2;
        puVar6[1] = (char)((ushort)uVar2 >> 8);
        *puVar6 = (char)uVar2;
        puVar6 = puVar7;
      } while (puVar4 + 0x1e != puVar7);
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar4,*(code **)(_r_modules_funcs_p + 0xe0));
    }
  }
  else {
    (**(code **)(_r_modules_funcs_p + 900))(*(code **)(_r_modules_funcs_p + 900));
    (**(code **)(_r_modules_funcs_p + 0x44))(&ecc_env,iVar3,*(code **)(_r_modules_funcs_p + 0x44));
  }
  if (_ecc_env != 0) {
                    /* WARNING: Could not recover jumptable at 0x00011ce6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(1,*(code **)(_r_modules_funcs_p + 0x108));
    return;
  }
  return;
}

