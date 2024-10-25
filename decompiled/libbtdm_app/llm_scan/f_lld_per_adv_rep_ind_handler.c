/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined2 *puVar5;
  undefined1 *puVar6;
  ushort *puVar7;
  byte bVar8;
  byte *pbVar9;
  int *piVar10;
  int iVar11;
  code *pcVar12;
  bool bVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int *__src;
  uint uVar17;
  uint uVar18;
  int iVar19;
  undefined1 auStack_48 [20];
  
  bVar1 = *param_1;
  uVar16 = (uint)bVar1;
  iVar15 = uVar16 * 0x44;
  piVar10 = (int *)(*(int *)(_p_llm_env + 8) + iVar15);
  if ((char)piVar10[0x10] == '\x0e') {
    uVar2 = *(undefined1 *)((int)piVar10 + 0x41);
    __src = piVar10 + 1;
    (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar10 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar15) = 0;
    (**(code **)(_r_ip_funcs_p + 0x3e0))(uVar16,*(code **)(_r_ip_funcs_p + 0x3e0));
    iVar11 = *(int *)(_p_llm_env + 8) + iVar15;
    *(undefined1 *)(iVar11 + 0x40) = 0xf;
    *(undefined2 *)(iVar11 + 0x2a) = 0xff;
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar16,5,1);
      (*(code *)*_bt_rf_coex_hooks_p)(uVar16,6,0,(code *)*_bt_rf_coex_hooks_p);
    }
    uVar3 = *(ushort *)(param_1 + 4);
    uVar4 = *(ushort *)(param_1 + 6);
    uVar18 = (uint)uVar3 * 2;
    iVar11 = *(int *)(_p_llm_env + 8) + iVar15;
    *(uint *)(iVar11 + 0x14) = (uint)uVar4;
    *(uint *)(iVar11 + 0x10) = uVar18;
    *(undefined4 *)(iVar11 + 0x18) = 2;
    *(undefined4 *)(iVar11 + 0x1c) = 2;
    *(ushort *)(iVar11 + 0x20) = (ushort)bVar1;
    *(undefined4 *)(iVar11 + 0x24) = 0;
    *(undefined1 *)(iVar11 + 0x22) = 0;
    if (uVar3 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    *(int *)(iVar11 + 0x18) = *(int *)(iVar11 + 0x18) + 3;
    *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x1c) + 3;
    pcVar12 = *(code **)(_r_ip_funcs_p + 0x6fc);
    *(uint *)(iVar11 + 0x14) = ((uVar4 - 1) + uVar18) % uVar18;
    (*pcVar12)(iVar11 + 0xc,pcVar12);
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
    bVar8 = param_1[2];
    *(undefined1 *)((int)puVar5 + 5) = uVar2;
    *(byte *)(puVar5 + 2) = bVar8;
    memcpy(puVar5 + 3,__src,6);
    *(undefined *)(puVar5 + 6) = (&co_rate_to_phy)[param_1[1]];
    puVar5[7] = *(undefined2 *)(param_1 + 4);
    *(byte *)(puVar5 + 8) = param_1[10];
    (**(code **)(_r_ip_funcs_p + 0x8c))(puVar5,*(code **)(_r_ip_funcs_p + 0x8c));
  }
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar15 + 0x40) == '\x0f') {
    uVar18 = (uint)param_1[0xe];
    uVar17 = (uint)param_1[0x18];
    do {
      uVar14 = uVar18;
      if (0xf7 < uVar18) {
        uVar14 = 0xf7;
      }
      puVar6 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,0x100,*(code **)(_r_modules_funcs_p + 200));
      *puVar6 = 0xf;
      *(ushort *)(puVar6 + 2) = (ushort)bVar1;
      puVar6[4] = param_1[0xb];
      puVar6[5] = (char)((int)*(short *)(_p_llm_env + 200) / 10) + param_1[0xc];
      puVar6[6] = 0xff;
      bVar8 = 1;
      if (uVar18 < 0xf8) {
        bVar8 = param_1[0xd];
      }
      puVar6[7] = bVar8;
      puVar6[8] = (char)uVar14;
      memcpy(puVar6 + 9,(void *)(*(int *)(param_1 + 0x14) + uVar17),uVar14);
      uVar18 = uVar18 - uVar14 & 0xff;
      (**(code **)(_r_ip_funcs_p + 0x8c))(puVar6,*(code **)(_r_ip_funcs_p + 0x8c));
      uVar17 = uVar17 + uVar14 & 0xff;
    } while (uVar18 != 0);
    iVar19 = *(int *)(_p_llm_env + 8) + iVar15;
    uVar18 = *(uint *)(iVar19 + 0x10);
    iVar11 = *(int *)(iVar19 + 0x14);
    if (uVar18 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)*(ushort *)(param_1 + 6) < *(uint *)(iVar19 + 0x10)) &&
       ((uint)*(ushort *)(param_1 + 6) != (iVar11 + 1U) % uVar18)) {
      (**(code **)(_r_ip_funcs_p + 0x6f4))(iVar19 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
      uVar3 = *(ushort *)(param_1 + 6);
      uVar18 = *(uint *)(iVar19 + 0x10);
      if (uVar18 == 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x94,*(code **)(_r_plf_funcs_p + 8));
      }
      pcVar12 = *(code **)(_r_ip_funcs_p + 0x6fc);
      *(uint *)(iVar19 + 0x14) = ((uVar3 - 1) + uVar18) % uVar18;
      (*pcVar12)(iVar19 + 0xc,pcVar12);
    }
    if (param_1[0x19] != 0) {
      bVar13 = false;
      for (uVar18 = 0; uVar18 < param_1[0x19]; uVar18 = uVar18 + uVar17 + 1 & 0xff) {
        iVar11 = *(int *)(param_1 + 0x14);
        pbVar9 = (byte *)((uint)param_1[0x1a] + iVar11 + uVar18);
        uVar17 = (uint)*pbVar9;
        bVar8 = pbVar9[1];
        if ((bVar13) || (bVar8 != 0x28)) {
          iVar11 = *(int *)(_p_llm_env + 8) + iVar15;
          if ((*(short *)(iVar11 + 0x2a) != 0xff) &&
             ((*(byte *)(iVar11 + 0x29) == bVar8 && ((int)uVar17 < (int)(param_1[0x19] - uVar18)))))
          {
            puVar7 = (ushort *)
                     (**(code **)(_r_modules_funcs_p + 200))
                               (1,0,uVar17 + 7,*(code **)(_r_modules_funcs_p + 200));
            *(undefined1 *)(puVar7 + 1) = 0;
            *(byte *)((int)puVar7 + 3) = bVar8;
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
          uVar14 = param_1[0x1a] + uVar18 & 0xff;
          memcpy(auStack_48,(void *)((uVar14 + 2 & 0xff) + iVar11),5);
          (**(code **)(_r_ip_funcs_p + 0x138))
                    (uVar16,auStack_48,*(undefined2 *)((uVar14 + 7 & 0xff) + iVar11),
                     *(code **)(_r_ip_funcs_p + 0x138));
          bVar13 = true;
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

