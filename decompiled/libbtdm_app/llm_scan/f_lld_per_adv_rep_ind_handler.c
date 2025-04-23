/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> f_lld_per_adv_rep_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_per_adv_rep_ind_handler(byte *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  ushort *puVar8;
  byte *pbVar9;
  byte bVar10;
  int *piVar11;
  int iVar12;
  code *pcVar13;
  int iVar14;
  uint uVar15;
  int *__src;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  undefined1 auStack_48 [20];
  
  bVar1 = *param_1;
  uVar15 = (uint)bVar1;
  iVar14 = uVar15 * 0x44;
  piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar14);
  if ((char)piVar11[0x10] == '\x0e') {
    uVar2 = *(undefined1 *)((int)piVar11 + 0x41);
    __src = piVar11 + 1;
    (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar11 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar14) = 0;
    (**(code **)(_r_ip_funcs_p + 0x3e0))(uVar15,*(code **)(_r_ip_funcs_p + 0x3e0));
    iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
    *(undefined1 *)(iVar12 + 0x40) = 0xf;
    *(undefined2 *)(iVar12 + 0x2a) = 0xff;
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar15,5,1);
      (*(code *)*_bt_rf_coex_hooks_p)(uVar15,6,0,(code *)*_bt_rf_coex_hooks_p);
    }
    uVar3 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 6);
    uVar19 = (uint)uVar3 * 2;
    iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
    *(uint *)(iVar12 + 0x14) = (uint)uVar4;
    *(uint *)(iVar12 + 0x10) = uVar19;
    *(undefined4 *)(iVar12 + 0x18) = 2;
    *(undefined4 *)(iVar12 + 0x1c) = 2;
    *(ushort *)(iVar12 + 0x20) = (ushort)bVar1;
    *(undefined4 *)(iVar12 + 0x24) = 0;
    *(undefined1 *)(iVar12 + 0x22) = 0;
    if (uVar3 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    *(int *)(iVar12 + 0x18) = *(int *)(iVar12 + 0x18) + 3;
    *(int *)(iVar12 + 0x1c) = *(int *)(iVar12 + 0x1c) + 3;
    pcVar13 = *(code **)(_r_ip_funcs_p + 0x6fc);
    *(uint *)(iVar12 + 0x14) = ((uVar4 - 1) + uVar19) % uVar19;
    (*pcVar13)(iVar12 + 0xc,pcVar13);
    uVar19 = (**(code **)(_r_ip_funcs_p + 0x4c8))(__src,uVar2,*(code **)(_r_ip_funcs_p + 0x4c8));
    if ((uVar19 < 0xc) && ((*(byte *)(uVar19 * 10 + _p_llm_env + 0x2d) & 4) != 0)) {
      (**(code **)(_r_ip_funcs_p + 0x25c))
                (__src,uVar2,1 << (param_1[2] & 0x1f) & 0xffff,*(code **)(_r_ip_funcs_p + 0x25c));
    }
    puVar6 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar6 = 0xe;
    puVar6[1] = (ushort)bVar1;
    *(byte *)(puVar6 + 2) = param_1[2];
    *(undefined1 *)((int)puVar6 + 5) = uVar2;
    memcpy(puVar6 + 3,__src,6);
    *(undefined *)(puVar6 + 6) = (&co_rate_to_phy)[param_1[1]];
    puVar6[7] = *(undefined2 *)(param_1 + 4);
    *(byte *)(puVar6 + 8) = param_1[10];
    (**(code **)(_r_ip_funcs_p + 0x8c))(puVar6,*(code **)(_r_ip_funcs_p + 0x8c));
  }
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar14 + 0x40) == '\x0f') {
    uVar19 = (uint)param_1[0xe];
    uVar17 = (uint)param_1[0x18];
    do {
      uVar16 = uVar19;
      if (0xf7 < uVar19) {
        uVar16 = 0xf7;
      }
      puVar7 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x100,*(code **)(_r_modules_funcs_p + 200));
      *puVar7 = 0xf;
      *(ushort *)(puVar7 + 2) = (ushort)bVar1;
      puVar7[4] = param_1[0xb];
      puVar7[5] = (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0xc];
      puVar7[6] = 0xff;
      bVar10 = 1;
      if (uVar19 < 0xf8) {
        bVar10 = param_1[0xd];
      }
      puVar7[7] = bVar10;
      puVar7[8] = (char)uVar16;
      memcpy(puVar7 + 9,(void *)(*(int *)(param_1 + 0x14) + uVar17),uVar16);
      uVar19 = uVar19 - uVar16 & 0xff;
      (**(code **)(_r_ip_funcs_p + 0x8c))(puVar7,*(code **)(_r_ip_funcs_p + 0x8c));
      uVar17 = uVar17 + uVar16 & 0xff;
    } while (uVar19 != 0);
    iVar18 = *(int *)(_p_llm_env + 8) + iVar14;
    uVar19 = *(uint *)(iVar18 + 0x10);
    iVar12 = *(int *)(iVar18 + 0x14);
    if (uVar19 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)*(ushort *)(param_1 + 6) < *(uint *)(iVar18 + 0x10)) &&
       ((uint)*(ushort *)(param_1 + 6) != (iVar12 + 1U) % uVar19)) {
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar18 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar3 = *(ushort *)(param_1 + 6);
      uVar19 = *(uint *)(iVar18 + 0x10);
      if (uVar19 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
      }
      pcVar13 = *(code **)(_r_ip_funcs_p + 0x6fc);
      *(uint *)(iVar18 + 0x14) = ((uVar3 - 1) + uVar19) % uVar19;
      (*pcVar13)(iVar18 + 0xc,pcVar13);
    }
    if (param_1[0x19] != 0) {
      bVar5 = false;
      for (uVar19 = 0; uVar19 < param_1[0x19]; uVar19 = uVar19 + 1 + uVar17 & 0xff) {
        iVar12 = *(int *)(param_1 + 0x14);
        pbVar9 = (byte *)((uint)param_1[0x1a] + iVar12 + uVar19);
        uVar17 = (uint)*pbVar9;
        bVar10 = pbVar9[1];
        if ((bVar5) || (bVar10 != 0x28)) {
          iVar12 = *(int *)(_p_llm_env + 8) + iVar14;
          if ((*(short *)(iVar12 + 0x2a) != 0xff) &&
             ((*(byte *)(iVar12 + 0x29) == bVar10 && ((int)uVar17 < (int)(param_1[0x19] - uVar19))))
             ) {
            puVar8 = (ushort *)
                     (**(code **)(_r_modules_funcs_p + 200))
                               (1,0,uVar17 + 7,*(code **)(_r_modules_funcs_p + 200));
            *(undefined1 *)(puVar8 + 1) = 0;
            *(byte *)((int)puVar8 + 3) = bVar10;
            uVar3 = *(ushort *)(param_1 + 8);
            *(char *)(puVar8 + 3) = (char)(uVar17 - 1);
            *puVar8 = (ushort)bVar1;
            iVar12 = *(int *)(param_1 + 0x14);
            puVar8[2] = uVar3;
            memcpy((void *)((int)puVar8 + 7),(void *)(iVar12 + 2 + (uint)param_1[0x1a] + uVar19),
                   uVar17 - 1);
            (**(code **)(_r_modules_funcs_p + 0xe0))(puVar8,*(code **)(_r_modules_funcs_p + 0xe0));
          }
        }
        else {
          uVar16 = param_1[0x1a] + uVar19 & 0xff;
          memcpy(auStack_48,(void *)((uVar16 + 2 & 0xff) + iVar12),5);
          (**(code **)(_r_ip_funcs_p + 0x138))
                    (uVar15,auStack_48,*(undefined2 *)((uVar16 + 7 & 0xff) + iVar12),
                     *(code **)(_r_ip_funcs_p + 0x138));
          bVar5 = true;
        }
      }
    }
  }
  if ((param_1[0xe] != 0) || (param_1[0x19] != 0)) {
    (**(code **)(_r_ip_funcs_p + 0x104))
              (*(undefined2 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
               *(code **)(_r_ip_funcs_p + 0x104));
  }
  return 0;
}

