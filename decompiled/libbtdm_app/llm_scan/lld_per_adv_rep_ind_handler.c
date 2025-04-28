/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> lld_per_adv_rep_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_per_adv_rep_ind_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  ushort *puVar7;
  int iVar8;
  byte *pbVar9;
  byte bVar10;
  int *piVar11;
  int iVar12;
  code *pcVar13;
  bool bVar14;
  int *__src;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  undefined1 auStack_48 [20];
  
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar8 + 0x18) == '\0') {
    return 0;
  }
  bVar1 = *param_1;
  uVar16 = (uint)bVar1;
  iVar8 = uVar16 * 0x44;
  piVar11 = (int *)(*(int *)(_p_llm_env + 8) + iVar8);
  if ((char)piVar11[0x10] == '\x0e') {
    uVar2 = *(undefined1 *)((int)piVar11 + 0x41);
    __src = piVar11 + 1;
    (**(code **)(_r_modules_funcs_p + 0xd8))
              (*piVar11 + -0xc,param_2,*(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar8) = 0;
    (**(code **)(_r_ip_funcs_p + 0x3e0))(uVar16,*(code **)(_r_ip_funcs_p + 0x3e0));
    iVar12 = *(int *)(_p_llm_env + 8) + iVar8;
    *(undefined1 *)(iVar12 + 0x40) = 0xf;
    *(undefined2 *)(iVar12 + 0x2a) = 0xff;
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar16,5,1);
      (*(code *)*_bt_rf_coex_hooks_p)(uVar16,6,0,(code *)*_bt_rf_coex_hooks_p);
    }
    uVar3 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 6);
    uVar18 = (uint)uVar3 * 2;
    iVar12 = *(int *)(_p_llm_env + 8) + iVar8;
    *(uint *)(iVar12 + 0x14) = (uint)uVar4;
    *(uint *)(iVar12 + 0x10) = uVar18;
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
    *(uint *)(iVar12 + 0x14) = ((uVar4 - 1) + uVar18) % uVar18;
    (*pcVar13)(iVar12 + 0xc,pcVar13);
    uVar18 = (**(code **)(_r_ip_funcs_p + 0x4c8))(__src,uVar2,*(code **)(_r_ip_funcs_p + 0x4c8));
    if ((uVar18 < 0xc) && ((*(byte *)(uVar18 * 10 + _p_llm_env + 0x2d) & 4) != 0)) {
      (**(code **)(_r_ip_funcs_p + 0x25c))
                (__src,uVar2,1 << (param_1[2] & 0x1f) & 0xffff,*(code **)(_r_ip_funcs_p + 0x25c));
    }
    puVar5 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar5 = 0xe;
    puVar5[1] = (ushort)bVar1;
    bVar10 = param_1[2];
    *(undefined1 *)((int)puVar5 + 5) = uVar2;
    *(byte *)(puVar5 + 2) = bVar10;
    memcpy(puVar5 + 3,__src,6);
    *(undefined *)(puVar5 + 6) = (&co_rate_to_phy)[param_1[1]];
    puVar5[7] = *(undefined2 *)(param_1 + 4);
    *(byte *)(puVar5 + 8) = param_1[10];
    (**(code **)(_r_ip_funcs_p + 0x8c))(puVar5,*(code **)(_r_ip_funcs_p + 0x8c));
  }
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40) == '\x0f') {
    uVar18 = (uint)param_1[0xe];
    uVar17 = (uint)param_1[0x18];
    do {
      uVar15 = uVar18;
      if (0xf7 < uVar18) {
        uVar15 = 0xf7;
      }
      puVar6 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x100,*(code **)(_r_modules_funcs_p + 200));
      *puVar6 = 0xf;
      *(ushort *)(puVar6 + 2) = (ushort)bVar1;
      puVar6[4] = param_1[0xb];
      puVar6[5] = (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0xc];
      puVar6[6] = 0xff;
      bVar10 = 1;
      if (uVar18 < 0xf8) {
        bVar10 = param_1[0xd];
      }
      puVar6[7] = bVar10;
      puVar6[8] = (char)uVar15;
      memcpy(puVar6 + 9,(void *)(*(int *)(param_1 + 0x14) + uVar17),uVar15);
      (**(code **)(_r_ip_funcs_p + 0x8c))(puVar6,*(code **)(_r_ip_funcs_p + 0x8c));
      uVar18 = uVar18 - uVar15 & 0xff;
      uVar17 = uVar17 + uVar15 & 0xff;
    } while (uVar18 != 0);
    iVar19 = *(int *)(_p_llm_env + 8) + iVar8;
    uVar18 = *(uint *)(iVar19 + 0x10);
    iVar12 = *(int *)(iVar19 + 0x14);
    if (uVar18 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)*(ushort *)(param_1 + 6) < *(uint *)(iVar19 + 0x10)) &&
       ((uint)*(ushort *)(param_1 + 6) != (iVar12 + 1U) % uVar18)) {
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar19 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar3 = *(ushort *)(param_1 + 6);
      uVar18 = *(uint *)(iVar19 + 0x10);
      if (uVar18 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
      }
      pcVar13 = *(code **)(_r_ip_funcs_p + 0x6fc);
      *(uint *)(iVar19 + 0x14) = ((uVar3 - 1) + uVar18) % uVar18;
      (*pcVar13)(iVar19 + 0xc,pcVar13);
    }
    if (param_1[0x19] != 0) {
      bVar14 = false;
      for (uVar18 = 0; uVar18 < param_1[0x19]; uVar18 = uVar17 + 1 + uVar18 & 0xff) {
        iVar12 = *(int *)(param_1 + 0x14);
        pbVar9 = (byte *)((uint)param_1[0x1a] + iVar12 + uVar18);
        uVar17 = (uint)*pbVar9;
        bVar10 = pbVar9[1];
        if ((bVar14) || (bVar10 != 0x28)) {
          iVar12 = *(int *)(_p_llm_env + 8) + iVar8;
          if ((*(short *)(iVar12 + 0x2a) != 0xff) &&
             ((*(byte *)(iVar12 + 0x29) == bVar10 && ((int)uVar17 < (int)(param_1[0x19] - uVar18))))
             ) {
            puVar7 = (ushort *)
                     (**(code **)(_r_modules_funcs_p + 200))
                               (1,0,uVar17 + 7,*(code **)(_r_modules_funcs_p + 200));
            *(undefined1 *)(puVar7 + 1) = 0;
            *(byte *)((int)puVar7 + 3) = bVar10;
            *puVar7 = (ushort)bVar1;
            uVar3 = *(ushort *)(param_1 + 8);
            *(char *)(puVar7 + 3) = (char)(uVar17 - 1);
            puVar7[2] = uVar3;
            memcpy((void *)((int)puVar7 + 7),
                   (void *)(*(int *)(param_1 + 0x14) + 2 + (uint)param_1[0x1a] + uVar18),uVar17 - 1)
            ;
            (**(code **)(_r_modules_funcs_p + 0xe0))(puVar7,*(code **)(_r_modules_funcs_p + 0xe0));
          }
        }
        else {
          uVar15 = param_1[0x1a] + uVar18 & 0xff;
          memcpy(auStack_48,(void *)((uVar15 + 2 & 0xff) + iVar12),5);
          (**(code **)(_r_ip_funcs_p + 0x138))
                    (uVar16,auStack_48,*(undefined2 *)((uVar15 + 7 & 0xff) + iVar12),
                     *(code **)(_r_ip_funcs_p + 0x138));
          bVar14 = true;
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

